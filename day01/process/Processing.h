#pragma once
#include "../data/Input.h"
#include <cstdint>

namespace day01::process
{
    class Processing
    {
    public:
        virtual ~Processing() = default;

        [[nodiscard]] virtual std::uint64_t process(data::Input& input) const = 0;
    };
} // namespace day01::reader
