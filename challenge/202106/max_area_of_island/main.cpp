#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>

int maxAreaOfIsLand(std::vector<std::vector<int>> &grid) {
    std::function<int(int row, int col)> f;
    int rows = grid.size();
    int cols = grid[0].size();
    f = [&f, &grid, rows, cols](int row, int col) -> int {
        grid[row][col] = 0;

        int ret = 1;
        if (row >= 1 && grid[row - 1][col] == 1) {
            ret += f(row - 1, col);
        }
        if (row + 1 < rows && grid[row + 1][col] == 1) {
            ret += f(row + 1, col);
        }
        if (col >= 1 && grid[row][col - 1] == 1) {
            ret += f(row, col - 1);
        }
        if (col + 1 < cols && grid[row][col + 1] == 1) {
            ret += f(row, col + 1);
        }
        return ret;
    };

    int ret = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
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
        std::vector<std::vector<int>> grid{
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
        assert(maxAreaOfIsLand(grid) == 6);
    }
    {
        std::vector<std::vector<int>> grid{
            {0, 0, 0, 0, 0, 0, 0, 0},
        };
        assert(maxAreaOfIsLand(grid) == 0);
    }
    return 0;
}
