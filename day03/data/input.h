#pragma once

#include <cstdint>
#include <vector>

namespace day03
{
    using number = std::uint32_t;

    struct NumberToMul
    {
        number Number1{};
        number Number2{};
    };

    using MulList = std::vector<NumberToMul>;
} // namespace day03
