#pragma once

#include "ReadingInput.h"

#include <filesystem>

namespace day01::reader
{
    class InputReader : public ReadingInput
    {
    public:
        InputReader(const std::filesystem::path& inputFilePath);

        virtual data::Input read() const override;

        private:
        const std::filesystem::path& inputFilePath;

    };
} // namespace day01::reader
