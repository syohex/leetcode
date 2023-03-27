#include <cassert>
#include <vector>
#include <algorithm>

int minPathSum(const std::vector<std::vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int limit = 1'000'000'000;

    std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, limit));
    dp[0][0] = grid[0][0];

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i != 0) {
                dp[i][j] = grid[i][j] + dp[i - 1][j];
            }
            if (j != 0) {
                dp[i][j] = std::min(dp[i][j], grid[i][j] + dp[i][j - 1]);
            }
        }
    }

    return dp[rows - 1][cols - 1];
}

int main() {
    {
        std::vector<std::vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
        int ret = minPathSum(grid);
        assert(ret == 7);
    }
    {
        std::vector<std::vector<int>> grid{{1, 2, 3}, {4, 5, 6}};
        int ret = minPathSum(grid);
        assert(ret == 12);
    }
    return 0;
}
