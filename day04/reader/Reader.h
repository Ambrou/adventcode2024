#pragma once

#include "../data/data.h"
#include <istream>

namespace day04 {
class Reader
{
    public:
    grid read(std::istream& inputStream)
    {
        grid grid{};
        std::string line{};
        while( std::getline(inputStream, line))
        {
            grid.push_back(line);
        }
        return grid;
    }
};
}
