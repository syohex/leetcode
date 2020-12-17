#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>

int maxAreaOfIsland(std::vector<std::vector<int>> &grid) {
    std::function<int(size_t x, size_t y)> f;
    f = [&f, &grid](size_t row, size_t col) -> int {
        grid[row][col] = 0;

        int ret = 1;
        if (col >= 1 && grid[row][col - 1] == 1) {
            ret += f(row, col - 1);
        }
        if (row >= 1 && grid[row - 1][col] == 1) {
            ret += f(row - 1, col);
        }
        if (col + 1 < grid[row].size() && grid[row][col + 1] == 1) {
            ret += f(row, col + 1);
        }
        if (row + 1 < grid.size() && grid[row + 1][col] == 1) {
            ret += f(row + 1, col);
        }

        return ret;
    };

    int ret = 0;
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == 1) {
                ret = std::max(ret, f(i, j));
            }
        }
    }

    return ret;
}

int main() {
    {
        // clang-format off
        std::vector<std::vector<int>> grid {
            {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
        };
        // clang-format on

        assert(maxAreaOfIsland(grid) == 6);
    }
    {
        // clang-format off
        std::vector<std::vector<int>> grid {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        };
        // clang-format on

        assert(maxAreaOfIsland(grid) == 0);
    }
    return 0;
}
