#include "InputReader.h"
#include <cstdint>
#include <stdexcept>
#include <fstream>

namespace day01::reader
{
InputReader::InputReader(const std::filesystem::path &inputFilePath) : inputFilePath{inputFilePath}
{
}

data::Input InputReader::read() const
{
    using namespace std::literals;

    std::ifstream file{inputFilePath.c_str()};
    data::Input inputData{};
    std::uint64_t firstNumber{};
    std::uint64_t secondNumber{};
    if (file.is_open())
    {
        while(file >> firstNumber >> secondNumber)
        {
            inputData.list1.push_back(firstNumber);
            inputData.list2.push_back(secondNumber);
        }
        file.close();
    }
    else
    {
        std::string error{"Impossible d'ouvrir le fichier "};
        throw std::runtime_error("Impossible d'ouvrir le fichier "s);
    }

    return inputData;
}
} // namespace day01::reader
