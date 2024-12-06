#include "InputReader.h"
#include <fstream>
#include <sstream>

namespace day02::reader
{
    InputReader::InputReader(const std::filesystem::path& inputFilePath) :
    inputFilePath{inputFilePath}
    {

    }

    data::reports InputReader::read() const
    {
        data::reports reports{};
        std::ifstream file{inputFilePath.c_str()};
        std::uint64_t firstNumber{};
        std::uint64_t secondNumber{};
        std::uint64_t thirdNumber{};
        std::uint64_t fourthNumber{};
        std::uint64_t fithNumber{};
        levels levels;
        if (file.is_open())
        {
            std::string line{};

            while( std::getline(file, line))
            {
                levels.clear();
                std::istringstream iss{line};
                std::uint64_t number{};
                while(iss >> number)
                {
                    levels.push_back(number);
                }
                reports.push_back(levels);
            };
            file.close();
        }
        else
        {
            throw std::runtime_error("Impossible d'ouvrir le fichier");
        }
        return reports;
    }
}
