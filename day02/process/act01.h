#pragma once

#include "process/processinh.h"

namespace day02::process {

    class act01 : public Prossessing
    {
        public:
[[nodiscard]] virtual std::uint32_t precalcul(const day02::data::reports &data) const override;
[[nodiscard]] virtual std::uint32_t calcul(const day02::data::reports &data) const override;
    };
}
