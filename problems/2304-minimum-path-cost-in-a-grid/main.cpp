#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>

int minPathCost(const std::vector<std::vector<int>> &grid, const std::vector<std::vector<int>> &moveCost) {
    int rows = grid.size();
    int cols = grid[0].size();

    std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, std::numeric_limits<int>::max()));

    for (int i = 0; i < cols; ++i) {
        dp[0][i] = grid[0][i];
    }

    for (int i = 0; i < rows - 1; ++i) {
        for (int j = 0; j < cols; ++j) {
            int costIndex = grid[i][j];
            for (int k = 0; k < cols; ++k) {
                int val = grid[i + 1][k] + dp[i][j] + moveCost[costIndex][k];
                dp[i + 1][k] = std::min(dp[i + 1][k], val);
            }
        }
    }

    int ret = std::numeric_limits<int>::max();
    for (int i = 0; i < cols; ++i) {
        ret = std::min(ret, dp[rows - 1][i]);
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> grid{{5, 3}, {4, 0}, {2, 1}};
        std::vector<std::vector<int>> moveCost{{9, 8}, {1, 5}, {10, 12}, {18, 6}, {2, 4}, {14, 3}};
        int ret = minPathCost(grid, moveCost);
        assert(ret == 17);
    }
    {
        std::vector<std::vector<int>> grid{{5, 1, 2}, {4, 0, 3}};
        std::vector<std::vector<int>> moveCost{{12, 10, 15}, {20, 23, 8}, {21, 7, 1}, {8, 1, 13}, {9, 10, 25}, {5, 3, 2}};
        int ret = minPathCost(grid, moveCost);
        assert(ret == 6);
    }
    return 0;
}