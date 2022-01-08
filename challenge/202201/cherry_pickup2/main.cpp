#include <cassert>
#include <vector>
#include <algorithm>
#include <functional>

int cherryPickup(const std::vector<std::vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    std::vector<std::vector<std::vector<int>>> dp(rows, std::vector<std::vector<int>>(cols, std::vector<int>(cols, -1)));
    std::function<int(int row, int col1, int col2)> f;
    f = [&](int row, int col1, int col2) -> int {
        if (col1 < 0 || col1 >= cols || col2 < 0 || col2 >= cols) {
            return 0;
        }

        if (dp[row][col1][col2] != -1) {
            return dp[row][col1][col2];
        }

        int ret = grid[row][col1];
        if (col1 != col2) {
            ret += grid[row][col2];
        }

        if (row != rows - 1) {
            int val = 0;
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    val = std::max(val, f(row + 1, col1 + i, col2 + j));
                }
            }

            ret += val;
        }

        dp[row][col1][col2] = ret;
        return ret;
    };

    return f(0, 0, cols - 1);
}

int main() {
    {
        std::vector<std::vector<int>> grid{
            {3, 1, 1},
            {2, 5, 1},
            {1, 5, 5},
            {2, 1, 1},
        };
        assert(cherryPickup(grid) == 24);
    }
    {
        std::vector<std::vector<int>> grid{
            {1, 0, 0, 0, 0, 0, 1}, {2, 0, 0, 0, 0, 3, 0}, {2, 0, 9, 0, 0, 0, 0}, {0, 3, 0, 5, 4, 0, 0}, {1, 0, 2, 3, 0, 0, 6},
        };
        assert(cherryPickup(grid) == 28);
    }
    return 0;
}
