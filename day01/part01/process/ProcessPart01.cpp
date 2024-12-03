#include "ProcessPart01.h"


#include <algorithm>
#include <numeric>
#include <cmath>

namespace day01::part01::process
{
    std::uint64_t ProcessPart01::process(data::Input& input) const
    {

        //auto left_range = input.list1 | std::ranges::views::all;
        //auto right_range = input.list2 | std::ranges::views::all | std::ranges::views::sort;


        std::ranges::sort(input.list1);
        std::ranges::sort(input.list2);

        auto sum_distances = std::inner_product(
            input.list1.begin(), input.list1.end(), input.list2.begin(), 0,
            std::plus<>(), [](int a, int b) { return std::abs(a - b); }
        );
        return sum_distances;
    }
}
