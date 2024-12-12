#include "act01.h"

#include <algorithm>
#include <ios>
#include <iostream>
#include <ranges>


namespace day02::process
{
std::uint32_t act01::precalcul(const day02::data::reports &reports) const
{
    std::uint32_t count{};
    for (auto &&report : reports)
    {
        for (auto &&level : report)
        {
            std::cout << level << " ";
        }

        std::cout << std::endl;
        const auto isSortedIncrease = std::ranges::is_sorted(report, std::ranges::less{});
        const auto isSortedDecrease = std::ranges::is_sorted(report, std::ranges::greater{});
        bool isShort = true;
        for (int i = 0; i < report.size() - 1; ++i)
        {
            std::cout << report[i] << " - " << report[i + 1] << " = " << report[i] - report[i + 1] << std::endl;
            if ( (report[i] - report[i + 1] > 3) || (report[i + 1] - report[i] > 3) ||
                (report[i + 1] - report[i] == 0))
            {
                isShort = false;
            }
        }

        std::cout << "is Croissant   " << std::boolalpha << isSortedIncrease << std::endl;
        std::cout << "is Decroissant " << std::boolalpha << isSortedDecrease << std::endl;
        std::cout << "is short        " << std::boolalpha << isShort << std::endl;

        if((isSortedIncrease || isSortedDecrease) && isShort)
        {
            std::cout << "pre increase counnter" << std::endl;
            count++;
        }
    }

    return count;
}

std::uint32_t act01::calcul(const day02::data::reports &reports) const
{
    int count{};
    for (auto &&report : reports)
    {
        const auto isSortedIncrease = std::ranges::is_sorted(report, std::ranges::less());
        const auto isSortedDecrease = std::ranges::is_sorted(report, std::ranges::greater{});
        bool isShort = true;
        for (int i = 0; i < report.size() - 1; ++i)
        {
            if((report[i] - report[i + 1] > 3) || (report[i + 1] - report[i] > 3) || (report[i + 1] - report[i] == 0))
            {
                isShort = false;
            }
        }

        if((isSortedIncrease || isSortedDecrease) && isShort)
        {
            std::cout << "increase counnter" << std::endl;
            count++;
        }
    }

    return count;
}
} // namespace day02::process
