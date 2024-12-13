#include "reader/Reader.h"
#include "process/Process.h"
#include <fstream>
#include <sstream>
#include <iostream>
;
using namespace day04;

int main()
{
    {
    std::istringstream iss{R"(MMMSXXMASM
MSAMXMSMSA
AMXSXMAAMM
MSAMASMSMX
XMASAMXAMM
XXAMMXXAMA
SMSMSASXSS
SAXAMASAAA
MAMMMXMMMM
MXMXAXMASX)"};
    //std::ifstream ifstream{"input.txt"};

    Reader reader{};

    auto grid = reader.read(iss);

    Process process{};
    std::cout << "day04 exemple 01 " << process.process01(grid) <<std::endl;

    //grid = reader.read(ifstream);
    //std::cout << "day04 real 01 " << process.process01(grid) <<std::endl;
    }

    {

    std::istringstream iss{R"(.M.S......
..A..MSMS.
.M.S.MAA..
..A.ASMSM.
.M.S.M....
..........
S.S.S.S.S.
.A.A.A.A..
M.M.M.M.M.
..........)"};
    std::ifstream ifstream{"input.txt"};

    Reader reader{};

    auto grid = reader.read(iss);

    Process process{};
    std::cout << "day04 exemple 02 " << process.process02(grid) <<std::endl;

    grid = reader.read(ifstream);
    std::cout << "day04 real 02 " << process.process02(grid) <<std::endl;


    }

    return 0;
}
