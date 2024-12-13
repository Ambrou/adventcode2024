#include "Parser.h"

#include <string>
#include <regex>
#include <ranges>
#include <iostream>

namespace day03
{
    Parser::Parser()
    {

    }

    MulList Parser::parse(std::istream &inputStream) const
    {
        std::string line{};
        std::regex pattern(R"(mul\((\d+),(\d+)\))");
        std::vector<std::pair<int, int>> results;

        MulList mulList{};

        while( std::getline(inputStream, line))
        {
            std::sregex_iterator it(line.begin(), line.end(), pattern);
            std::sregex_iterator end;

            while (it != end)
            {
                std::smatch match = *it;
                number first = std::stoi(match[1]);
                number second = std::stoi(match[2]);
                mulList.push_back(NumberToMul{.Number1 = first, .Number2 = second});
                ++it;
            }

            for (const auto &mul : mulList)
            {
                std::cout << "(" << mul.Number1 << ", " << mul.Number2 << ")" << std::endl;
            }

        };
        return mulList;
    }
}
