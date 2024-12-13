#include "./parser/Parser.h"
#include "process/Process01.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace day03;

int main()
{
    std::istringstream iss{"xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))"};
    std::ifstream ifstream{"input.txt"};
    Parser parser{};
    Process01 process{};

    {
        const auto list = parser.parse(iss);
        std::cout << "exemple 1 : " << process.process(list) << std::endl;
    }
    {
        const auto list = parser.parse(ifstream);
        std::cout << "exemple 1 : " << process.process(list) << std::endl;
    }
}
