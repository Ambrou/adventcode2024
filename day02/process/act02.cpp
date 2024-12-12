#include "act02.h"

#include <algorithm>
#include <cstdint>
#include <ios>
#include <iostream>
#include <ranges>
#include <cmath>


namespace day02::process
{

    auto isIncrease = [](auto levels) -> bool
    {
        auto a = levels | std::views::adjacent<2> |
                 std::views::transform([](auto pair) { return std::get<1>(pair) - std::get<0>(pair); }); 

        return std::ranges::all_of(a, [](auto n) { return n > 0; });
    };

    auto isDecrease = [](auto levels) -> bool {
        auto a = levels | std::views::adjacent<2> |
                 std::views::transform([](auto pair) { return std::get<1>(pair) - std::get<0>(pair); });

        return std::ranges::all_of(a, [](auto n) { return n < 0; });
    };

    auto isStepSafe = [](auto levels) -> bool {
        auto a = levels | std::views::adjacent<2> |
                 std::views::transform([](auto pair) { return std::get<1>(pair) - std::get<0>(pair); });

        return (std::ranges::find_if(a, [](auto n) { return n == 0 || std::abs(n) > 3; }) == a.end());
    };

    auto isStrictSafe = [](auto levels) -> bool {
        return ((isIncrease(levels) || isDecrease(levels)) && isStepSafe(levels));
    };

    auto isSafe = [](auto levels) -> bool
    {
        if (isStrictSafe(levels))
        {
            return true;
        }
        for (auto i = 0; i < levels.size(); ++i)
        {
            auto v = levels | std::views::enumerate |
                     std::views::filter([&i](const auto &pair) { return std::get<0>(pair) != i; }) |
                     std::views::elements<1>;
            

            /*std::cout << std::endl;
            std::ranges::for_each(v, [](auto e) { std::cout << e << " "; });*/

            if (isStrictSafe(v))
            {
                
                //std::cout << "is Croissant   " << std::boolalpha << isIncrease(v) << std::endl;
                //std::cout << "is Decroissant " << std::boolalpha << isDecrease(v) << std::endl;
                //std::cout << "is short        " << std::boolalpha << isStepSafe(v) << std::endl;
                return true;
            }
        }
       
        return false;

    };
    std::uint32_t act02::precalcul(const day02::data::reports &reports) const
    {
        day02::data::reports r = reports;

         std::uint32_t count{};

          std::ranges::for_each(r, [&count](auto levels) {
             if (isSafe(levels))
             {
                 count++;
             }
         });
        //for (auto levels : r)
        //{
        //    if(isSafe(levels))
        //    {
        //        count++;
        //    }

        //    //for (auto &&level : report)
        //    //{
        //    //    std::cout << level << " ";
        //    //}

        //    //std::cout << std::endl;
        //    //const auto isSortedIncrease = std::ranges::is_sorted(report, std::ranges::greater{});

        //    //if (!isSortedIncrease) {
        //    //    // Try to make it increase
        //    //}

        //    //const auto isSortedDecrease = std::ranges::is_sorted(report, std::ranges::less{});


        //    ////if(!isSortedIncrease)
        //    ////{
        //    ////    // try to make it croissant
        //    ////    auto it = std::ranges::adjacent_find(report, ranges::greater()); it == report.end());

        //    ////}



        //    //bool isShort = true;
        //    //for (int i = 0; i < report.size() - 1; ++i)
        //    //{
        //    //    std::cout << report[i] << " - " << report[i + 1] << " = " << report[i] - report[i + 1] << std::endl;
        //    //    if((report[i] - report[i + 1] > 3) || (report[i + 1] - report[i] > 3) || (report[i + 1] - report[i] == 0))
        //    //    {
        //    //        isShort = false;
        //    //    }
        //    //}

        //    //std::cout << "is Croissant   " << std::boolalpha << isSortedIncrease << std::endl;
        //    //std::cout << "is Decroissant " << std::boolalpha << isSortedDecrease << std::endl;
        //    //std::cout << "is short        " << std::boolalpha << isShort << std::endl;

        //    //if((isSortedIncrease || isSortedDecrease) && isShort)
        //    //{
        //    //    std::cout << "pre increase counter" << std::endl;
        //    //    count++;
        //    //}
        //}

        return count;
    }

    std::uint32_t act02::calcul(const day02::data::reports &reports) const
    {
        day02::data::reports r = reports;

        std::uint32_t count{};

        std::ranges::for_each(r, [&count](auto levels) {
            if (isSafe(levels))
            {
                count++;
            }
        });
        return count;
    }
}
