#pragma  once
#include "../data/data.h"

#include <cstdint>
namespace day04 {
class Process
{
public:
    std::uint64_t process01(const grid& grid)
    {
        std::uint64_t result{};
        const std::uint64_t rows = grid.size();
        const std::uint64_t cols = grid.at(0).size();
        const std::string TARGET = "XMAS";

        std::vector<std::pair<int, int>> directions = {
            {0, 1}, {1, 0}, {1, 1}, {1, -1},
            {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}
        };

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                for (const auto& dir : directions) {
                    std::string word;
                    int x = i;
                    int y = j;
                    for (int k = 0; k < 4; ++k) {
                        if (x >= 0 && x < rows && y >= 0 && y < cols) {
                            word += grid[x][y];
                            x += dir.first;
                            y += dir.second;
                        }
                    }
                    if (word == TARGET) {
                        result++;
                    }
                }
            }
        }
        return result;
    }

    std::uint64_t process02(const grid& grid)
    {
        std::uint64_t result{};
        const std::int64_t rows = grid.size();
        const std::int64_t cols = grid.at(0).size();

        bool b1 = isCrossPattern(grid, 1, 2, rows, cols);
        bool b7 = isCrossPattern(grid, 2, 6, rows, cols);
        bool b8 = isCrossPattern(grid, 2, 7, rows, cols);
        bool b2 = isCrossPattern(grid, 3, 2, rows, cols);
        bool b6 = isCrossPattern(grid, 3, 4, rows, cols);
        bool b3 = isCrossPattern(grid, 7, 1, rows, cols);
        bool b4 = isCrossPattern(grid, 7, 3, rows, cols);
        bool b5 = isCrossPattern(grid, 7, 5, rows, cols);
        bool b9 = isCrossPattern(grid, 7, 7, rows, cols);

        for (std::int64_t i = 0; i < rows; ++i) {
            for (std::int64_t j = 0; j < cols; ++j) {
                if (isCrossPattern(grid, i, j, rows, cols)) {
                result++;
                }
            }
        }
        return result;
    }


    bool isCrossPattern(const std::vector<std::string>& grid, std::int64_t x, std::int64_t y, std::int64_t rows, std::int64_t cols)
    {
        if (x - 1 < 0 || x + 1 >= rows || y - 1 < 0 || y + 1 >= cols) {
            return false;
        }

    char center = grid[x][y];
    if (center != 'A') return false;

    // Vérifier les quatre orientations possibles
    return (
        // M.S  S.S  M.M  S.M
        // .A.  .A.  .A.  .A.
        // M.S  M.M  S.S  S.M
        (grid[x - 1][y - 1] == 'M' && grid[x + 1][y - 1] == 'M' && grid[x + 1][y + 1] == 'S' && grid[x - 1][y + 1] == 'S') ||
        (grid[x - 1][y - 1] == 'S' && grid[x + 1][y - 1] == 'M' && grid[x + 1][y + 1] == 'M' && grid[x - 1][y + 1] == 'S') ||
        (grid[x - 1][y - 1] == 'M' && grid[x + 1][y - 1] == 'S' && grid[x + 1][y + 1] == 'S' && grid[x - 1][y + 1] == 'M') ||
        (grid[x - 1][y - 1] == 'S' && grid[x + 1][y - 1] == 'S' && grid[x + 1][y + 1] == 'M' && grid[x - 1][y + 1] == 'M')
        //(grid[x-1][y] == 'S' && grid[x+1][y] == 'M' && grid[x][y-1] == 'S' && grid[x][y+1] == 'M') ||
        //(grid[x-1][y] == 'M' && grid[x+1][y] == 'S' && grid[x][y-1] == 'M' && grid[x][y+1] == 'S') ||
        //(grid[x-1][y] == 'S' && grid[x+1][y] == 'S' && grid[x][y-1] == 'M' && grid[x][y+1] == 'M')
    );
}

};
}
