
#include "data.h"

#include <cstdint>
#include <iostream>
#include <ranges>
#include <regex>
#include <sstream>
#include <fstream>


using namespace day05;

std::int32_t main()
{
//     std::istringstream iss{R"(47|53
// 97|13
// 97|61
// 97|47
// 75|29
// 61|13
// 75|53
// 29|13
// 97|29
// 53|29
// 61|53
// 97|53
// 61|29
// 47|13
// 75|47
// 97|75
// 47|61
// 75|61
// 47|29
// 75|13
// 53|13

// 75,47,61,53,29
// 97,61,53,29,13
// 75,29,13
// 75,97,47,61,53
// 61,13,29
// 97,13,75,29,47)"};

    std::ifstream iss{"./input.txt"};

    //std::string line;

    //const auto isPageOrder = [](const auto &str) { return str.find("|") != std::string::npos; };

    // auto pagesOrder = std::views::istream<std::string>(iss) |
    //                   std::views::take_while([](const auto &str) { return str.find("|") != std::string::npos; })
    //                 | std::views::transform([](const std::string& s) {
    //                 std::regex number_regex("(\\d+)\\|(\\d+)");
    //                 std::smatch match;
    //                 if (std::regex_search(s, match, number_regex)) {

    //                     return PageOrder{std::stoi(match[1]), std::stoi(match[2])};
    //                 }
    //                 return PageOrder{}; // ou une valeur par défaut si aucun nombre n'est trouvé
    //             });

    class A{
        public:
        std::vector<std::int32_t> list{};
        bool isValid{true};
        bool isCorrected{false};
    };
    std::vector<PageOrder> pagesOrder{};
    std::vector<A> pagesUpdates{};
    for (const auto &str : std::views::istream<std::string>(iss))
    {
        if(str.find("|") != std::string::npos) {
            std::regex number_regex("(\\d+)\\|(\\d+)");
            std::smatch match;
            if (std::regex_search(str, match, number_regex)) {
                pagesOrder.push_back(PageOrder{std::stoi(match[1]), std::stoi(match[2])});
            }
        }
        else if (str.find(",") != std::string::npos) {
            //auto a =
            pagesUpdates.push_back(A{.list = str | std::views::split(',') | std::views::transform([](auto &&rng) {
                              int n{};
                              std::from_chars(rng.data(), rng.data() + rng.size(), n);
                              return n;
                          }) | std::ranges::to<std::vector>()});
        }
    }

    for (auto&& pagesUpdate : pagesUpdates) {
        //std::cout << std::endl;
        for(auto&& bbbb : pagesUpdate.list)
        {
          //  std::cout << bbbb << " ";
        }
        //std::cout << std::endl;
        for (auto&& pageOrder : pagesOrder) {
            if (pagesUpdate.isValid) {
                //std::cout << pageOrder.PageBefore << " " << pageOrder.PageAfter << std::endl;;
                const auto& after = std::ranges::find(pagesUpdate.list, pageOrder.PageAfter);
                const auto& before = std::ranges::find(pagesUpdate.list, pageOrder.PageBefore);
                if( after != pagesUpdate.list.end() &&
                    before != pagesUpdate.list.end()) {
                       // std::cout << std::distance(before, after) << std::endl;
                    if(std::distance(before, after) < 0) {
                        pagesUpdate.isValid = false;
                        // std::iter_swap(before, after);
                        // pagesUpdate.isCorrected = true;
                        break;
                        // std::cout << *before << " " << *after << std::endl;
                        // std::cout << pagesUpdate.at(pagesUpdate.size() / 2 + 1) << std::endl;
                        // result += pagesUpdate.at(pagesUpdate.size() / 2 + 1);
                    }
                }
            }
        }

        // for (auto&& pageOrder : pagesOrder) {
        //     if (!pagesUpdate.isValid) {
        //         //std::cout << pageOrder.PageBefore << " " << pageOrder.PageAfter << std::endl;;
        //         const auto& after = std::ranges::find(pagesUpdate.list, pageOrder.PageAfter);
        //         const auto& before = std::ranges::find(pagesUpdate.list, pageOrder.PageBefore);
        //         if( after != pagesUpdate.list.end() &&
        //             before != pagesUpdate.list.end()) {
        //                // std::cout << std::distance(before, after) << std::endl;
        //             if(std::distance(before, after) < 0) {
        //                 //pagesUpdate.isValid = false;
        //                 for(auto&& bbbb : pagesUpdate.list)
        //                 {
        //                     std::cout << bbbb << " ";
        //                 }
        //                 std::cout << std::endl;

        //                  std::cout << *before << " " << *after << std::endl;
        //                  std::iter_swap(before, after);


        //                 for(auto&& bbbb : pagesUpdate.list)
        //                 {
        //                     std::cout << bbbb << " ";
        //                 }
        //                 std::cout << std::endl;

        //                  pagesUpdate.isCorrected = true;
        //                 // std::cout << pagesUpdate.at(pagesUpdate.size() / 2 + 1) << std::endl;
        //                 // result += pagesUpdate.at(pagesUpdate.size() / 2 + 1);
        //             }
        //         }
        //     }
        // }

    }


    for (int i = 0; i < 50; ++i)
    {
    for (auto&& pageOrder : pagesOrder) {
        for (auto&& pagesUpdate : pagesUpdates) {
            if (!pagesUpdate.isValid) {
                //std::cout << pageOrder.PageBefore << " " << pageOrder.PageAfter << std::endl;;
                const auto& after = std::ranges::find(pagesUpdate.list, pageOrder.PageAfter);
                const auto& before = std::ranges::find(pagesUpdate.list, pageOrder.PageBefore);
                if( after != pagesUpdate.list.end() &&
                    before != pagesUpdate.list.end()) {
                       // std::cout << std::distance(before, after) << std::endl;
                    if(std::distance(before, after) < 0) {
                        //pagesUpdate.isValid = false;
                        for(auto&& bbbb : pagesUpdate.list)
                        {
                            // std::cout << bbbb << " ";
                        }
                        // std::cout << std::endl;

                        //  std::cout << *before << " " << *after << std::endl;
                         std::iter_swap(before, after);


                        for(auto&& bbbb : pagesUpdate.list)
                        {
                            // std::cout << bbbb << " ";
                        }
                        // std::cout << std::endl;

                         pagesUpdate.isCorrected = true;
                        // std::cout << pagesUpdate.at(pagesUpdate.size() / 2 + 1) << std::endl;
                        // result += pagesUpdate.at(pagesUpdate.size() / 2 + 1);
                    }
                }
            }
        }
    }
    }
        //std::cout << std::endl;

    std::uint32_t result{};
    std::uint32_t result2{};
    for (auto&& pagesUpdate : pagesUpdates) {
        if(pagesUpdate.isValid)
        {
            //std::cout << std::endl;
            for(auto&& bbbb : pagesUpdate.list)
            {
                //std::cout << bbbb << " ";
            }

            //std::cout << "position " << pagesUpdate.list.size() / 2 << std::endl;
            //std::cout << pagesUpdate.list.at(pagesUpdate.list.size() / 2 ) << std::endl;
            result += pagesUpdate.list.at(pagesUpdate.list.size() / 2);
        }
        else if(pagesUpdate.isCorrected){
            for(auto&& bbbb : pagesUpdate.list)
            {
                // std::cout << bbbb << " ";
            }
            // std::cout << "position " << pagesUpdate.list.size() / 2 << std::endl;
            // std::cout << pagesUpdate.list.at(pagesUpdate.list.size() / 2 ) << std::endl;
            result2 += pagesUpdate.list.at(pagesUpdate.list.size() / 2);
        }
    }

    std::cout << result << std::endl;
    std::cout << result2 << std::endl;
    // auto pagesOrder = std::views::istream<std::string>(iss) | std::views::all() |
    //                   std::views::take_while([](const auto &str) { return str.find(",") == std::string::npos; });
    // for (auto pageOrder : pagesOrder)
    // {
    //     std::cout << pageOrder << std::endl;
    //     //std::cout << pageOrder.PageBefore << " " << pageOrder.PageAfter << std::endl;
    // }

    // auto pagesUpdates = std::views::istream<std::string>(iss) |
    //                   std::views::take_while([](const auto &str) { return str.find(",") != std::string::npos; });
    // for (auto pageUpdate : pagesUpdates)
    // {
    //     std::cout << pageUpdate << std::endl;
    //     //std::cout << pageOrder.PageBefore << " " << pageOrder.PageAfter << std::endl;
    // }
    // auto parse_line = [](const std::string &line) {
    //     return line | std::views::split(',') | std::views::transform([](auto &&rng) {
    //                std::cout << "a " << rng.data() << std::endl;
    //                int n;
    //                std::from_chars(rng.data(), rng.data() + rng.size(), n);
    //                return n;
    //            });
    // };

    // auto pagesUpdates = std::views::istream<std::string>(iss) |
    //                     std::views::drop_while([](const auto &str) {
    //                         std::cout << "b " << str << std::endl;
    //                         return str.find("|") != std::string::npos;
    //                     })
    //                     // | std::views::split(',')
    //                     | std::views::transform([](auto &&rng) {
    //                           std::cout << "a " << rng.data() << std::endl;
    //                           int n = 0;
    //                           //std::from_chars(rng.data(), rng.data() + rng.size(), n);
    //                           return n;
    //                       });
    // ;
    // // | std::views::transform(parse_line);


    // for (auto &&pagesUpdate : pagesUpdates)
    // {
    //     for (auto &&pageOrder : pagesOrder)
    //     {
    //         std::cout << pageOrder.PageBefore << " " << pageOrder.PageAfter << std::endl;
    //         //auto after = std::ranges::find(pagesUpdate, pageOrder.PageAfter);
    //         //auto before = std::ranges::find(pagesUpdate, pageOrder.PageBefore);
    //         //if (after != pagesUpdate.end() && before != pagesUpdate.end())
    //         ////for (auto n : pagesUpdate)
    //         {
    //             // std::cout << *after << " " << *before << std::endl;
    //         }
    //     }

    //     std::cout << std::endl;
    //     //std::cout << pageOrder.PageBefore << " " << pageOrder.PageAfter << std::endl;
    // }

    //int result{};
    //for(auto p : pagesUpdates)
    //{
    //    // for(auto q : p)
    //    // {
    //    //     std::cout << q << std::endl;
    //    // }
    //    for(auto r : pagesOrder)
    //    {
    //        const auto a = std::ranges::find(p, r.PageAfter);
    //        const auto b = std::ranges::find(p, r.PageBefore);
    //        if(a != p.end() && b != p.end() )
    //        {
    //            auto after = *a;
    //            auto before = *b;
    //            if(before < after)
    //            {
    //                int aaaaaa = 12;
    //             //   result += p[p.size()/2 + 1];
    //            }
    //        }
    //    }
    //}

    //std::cout << result;
    return 0;
}
