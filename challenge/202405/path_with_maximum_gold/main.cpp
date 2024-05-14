#include <cassert>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>

int getMaximumGold(const std::vector<std::vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    std::function<int(int row, int col, int sum, std::vector<std::vector<bool>> &checked)> f;
    f = [&](int row, int col, int sum, std::vector<std::vector<bool>> &checked) -> int {
        checked[row][col] = true;

        sum += grid[row][col];

        int v1 = 0;
        if (row - 1 >= 0 && !checked[row - 1][col] && grid[row - 1][col] != 0) {
            v1 = f(row - 1, col, sum, checked);
        }

        int v2 = 0;
        if (col - 1 >= 0 && !checked[row][col - 1] && grid[row][col - 1] != 0) {
            v2 = f(row, col - 1, sum, checked);
        }
        int v3 = 0;
        if (row + 1 < rows && !checked[row + 1][col] && grid[row + 1][col] != 0) {
            v3 = f(row + 1, col, sum, checked);
        }
        int v4 = 0;
        if (col + 1 < cols && !checked[row][col + 1] && grid[row][col + 1] != 0) {
            v4 = f(row, col + 1, sum, checked);
        }

        int ret = std::max({sum, v1, v2, v3, v4});
        checked[row][col] = false;
        return ret;
    };

    std::vector<std::vector<bool>> checked(rows, std::vector<bool>(cols, false));
    int ret = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] != 0) {
                ret = std::max(ret, f(i, j, 0, checked));
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> grid{
            {0, 6, 0},
            {5, 8, 7},
            {0, 9, 0},
        };
        int ret = getMaximumGold(grid);
        assert(ret == 24);
    }
    {
        std::vector<std::vector<int>> grid{
            {1, 0, 7}, {2, 0, 6}, {3, 4, 5}, {0, 3, 0}, {9, 0, 20},
        };
        int ret = getMaximumGold(grid);
        assert(ret == 28);
    }
    return 0;
}
