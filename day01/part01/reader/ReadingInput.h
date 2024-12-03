#pragma once

#include "../data/Input.h"

namespace day01::reader
{
    class ReadingInput
    {
    public:
        virtual ~ReadingInput() = default;

        [[nodiscard]] virtual data::Input read() const = 0;
    };
} // namespace day01::reader
