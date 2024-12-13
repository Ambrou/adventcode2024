#include "Parser.h"

#include <string>
#include <regex>
#include <ranges>
#include <iostream>

namespace day03
{

    MulList Parser::parse01(std::istream &inputStream) const
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

            // for (const auto &mul : mulList)
            // {
            //     std::cout << "(" << mul.Number1 << ", " << mul.Number2 << ")" << std::endl;
            // }

        };
        return mulList;
    }

    MulList Parser::parse02(std::istream &inputStream) const
    {
        std::string line{};
        std::regex pattern(R"(mul\(([\d]+),([\d]+)\)|don't\(\)|do\(\))");
        std::vector<std::pair<int, int>> results;

        MulList mulList{};
        bool mulToAdd{true};
        while( std::getline(inputStream, line))
        {
            std::sregex_iterator it(line.begin(), line.end(), pattern);
            std::sregex_iterator end;

            while (it != end)
            {

                std::smatch match = *it;
                //std::cout << match.str() << std::endl;
                if(match.str() == R"(don't())")
                {
                    mulToAdd = false;
                }
                else if(match.str() == R"(do())")
                {
                    mulToAdd = true;
                }
                else
                {
                    if(mulToAdd)
                    {
                        const number first = std::stoi(match[1]);
                        const number second = std::stoi(match[2]);
                        mulList.push_back(NumberToMul{.Number1 = first, .Number2 = second});
                    }
                }

                ++it;
            }

            // for (const auto &mul : mulList)
            // {
            //     std::cout << "(" << mul.Number1 << ", " << mul.Number2 << ")" << std::endl;
            // }

        };
        return mulList;
    }
}
