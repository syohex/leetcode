#include <cassert>
#include <vector>
#include <functional>

int numIslands(std::vector<std::vector<char>> &grid) {
    std::function<void(int row, int col)> f;
    f = [&f, &grid](int row, int col) {
        grid[row][col] = '0';

        if (row >= 1 && grid[row - 1][col] == '1') {
            grid[row - 1][col] = '0';
            f(row - 1, col);
        }
        if (col >= 1 && grid[row][col - 1] == '1') {
            grid[row][col - 1] = '0';
            f(row, col - 1);
        }
        if (row + 1 < grid.size() && grid[row + 1][col] == '1') {
            grid[row + 1][col] = '0';
            f(row + 1, col);
        }
        if (col + 1 < grid[row].size() && grid[row][col + 1] == '1') {
            grid[row][col + 1] = '0';
            f(row, col + 1);
        }
    };

    int ret = 0;
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == '1') {
                ++ret;
                f(i, j);
            }
        }
    }

    return ret;
}

int main() {
    {
        // clang-format off
        std::vector<std::vector<char>> grid {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'},
        };
        // clang-format on

        assert(numIslands(grid) == 1);
    }
    {
        // clang-format off
        std::vector<std::vector<char>> grid {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'},
        };
        // clang-format on

        assert(numIslands(grid) == 3);
    }
    {
        // clang-format off
        std::vector<std::vector<char>> grid {
            {'1'},
        };
        // clang-format on

        assert(numIslands(grid) == 1);
    }
    return 0;
}
