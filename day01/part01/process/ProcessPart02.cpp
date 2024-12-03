#include "ProcessPart02.h"


#include <algorithm>
#include <numeric>
#include <cmath>
#include <algorithm>

namespace day01::part01::process
{
    std::uint64_t ProcessPart02::process(data::Input& input) const
    {

        std::uint64_t res{};
        for (auto&& element : input.list1) {
            const auto multiplieur {std::ranges::count(input.list2.begin(), input.list2.end(), element)};
            res += element * multiplieur;
        }


        return res;
    }
}
