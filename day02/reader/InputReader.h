#include "data/reports.h"
#include <filesystem>

namespace day02::reader
{
    class InputReader
    {
        public:
            explicit InputReader(const std::filesystem::path& inputFilePath);
            [[nodiscard]] data::reports read() const;

            private:
            const std::filesystem::path& inputFilePath;
    };
}
