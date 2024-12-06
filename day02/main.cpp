#include "data/reports.h"
#include "reader/InputReader.h"
#include "process/act01.h"

#include <iostream>

using namespace day02::reader;
using namespace day02::process;

int main()
{

    std::cout << "Hello Day 02" << std::endl;

    const InputReader inputReader{"input.txt"};

    const auto inputDate {inputReader.read()};

    const auto act1 = act01{};

    const day02::data::reports precalcul
    {
        levels{7, 6, 4, 2, 1},
        levels{1, 2, 7, 8, 9},
        levels{9, 7, 6, 2, 1},
        levels{1, 3, 2, 4, 5},
        levels{8, 6, 4, 4, 1},
        levels{1, 3, 6, 7, 9}
        // levels{65, 67, 70, 72, 74, 73},
        // levels{32, 35, 37, 39, 39}
    };

    const auto p1 = act1.precalcul(precalcul);
    const auto r1 = act1.calcul(inputDate);

    std::cout << "Act 01 = " << p1 <<  std::endl;
    std::cout << "Act 01 = " << r1 <<  std::endl;
    std::cout << "Bye Day 02" << std::endl;

    return r1;
}
