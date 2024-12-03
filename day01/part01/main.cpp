#include "../data/Input.h"
#include "./reader/InputReader.h"
#include "./process/ProcessPart01.h"
#include "./process/ProcessPart02.h"

#include <cstdint>
#include <iostream>

using namespace day01;
using namespace data;

int main(int argc, char* argv[])
{
    const day01::reader::InputReader inputReader{"input.txt"};

    // read Input
    Input input{inputReader.read()};

    {
        // process
        const day01::part01::process::ProcessPart01 process{};
        const auto result {process.process(input)};

        // display result
        std::cout << "part  01 = " << result << std::endl;
    }



    {
        // process
        const day01::part01::process::ProcessPart02 process{};
        const auto result {process.process(input)};

        // display result
        std::cout << "part  02 = " << result << std::endl;
    }
    // return it for fun
    return 0;
}
