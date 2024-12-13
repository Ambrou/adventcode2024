#include "Process01.h"

namespace day03
{
    std::uint32_t Process01::process(const MulList& mulList) const
    {
        std::uint32_t result{0};

        for (auto&& mul : mulList) {
            result +=  mul.Number1 * mul.Number2;

        }

        return result;
    }
}
