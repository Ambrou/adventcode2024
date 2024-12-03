#pragma once

#include "../process/Processing.h"

namespace day01::part01::process {
    class ProcessPart01 : public ::day01::process::Processing
    {
        public:
        [[nodiscard]] virtual std::uint64_t process(data::Input& input) const override;
    };
}
