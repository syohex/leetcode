#include <cassert>
#include <vector>

int uniquePathsWithObstacles(const std::vector<std::vector<int>> &obstacleGrid) {
    int rows = obstacleGrid.size();
    int cols = obstacleGrid[0].size();
    std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));

    if (obstacleGrid[0][0] == 0) {
        dp[0][0] = 1;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (obstacleGrid[i][j] == 1) {
                continue;
            }

            if (i >= 1 && obstacleGrid[i - 1][j] == 0) {
                dp[i][j] += dp[i - 1][j];
            }
            if (j >= 1 && obstacleGrid[i][j - 1] == 0) {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }

    return dp.back().back();
}

int main() {
    {
        std::vector<std::vector<int>> matrix{
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0},
        };
        assert(uniquePathsWithObstacles(matrix) == 2);
    }
    {
        std::vector<std::vector<int>> matrix{
            {0, 1},
            {0, 0},
        };
        assert(uniquePathsWithObstacles(matrix) == 1);
    }
    {
        std::vector<std::vector<int>> matrix{
            {1},
        };
        assert(uniquePathsWithObstacles(matrix) == 0);
    }
    return 0;
}
