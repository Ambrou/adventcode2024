#pragma once
#include "data/reports.h"
#include <cstdint>

namespace day02::process
{
    class Prossessing
    {
        public:
        virtual ~Prossessing() = default;
        [[nodiscard]] virtual std::uint32_t precalcul(const day02::data::reports &data) const = 0;
        [[nodiscard]] virtual std::uint32_t calcul(const day02::data::reports &data) const = 0;
    };
}
