#include <cassert>
#include <vector>
#include <cstdio>

int uniquePathsWithObstacles(const std::vector<std::vector<int>> &obstacleGrid) {
    std::vector<std::vector<int>> table(obstacleGrid.size());
    for (size_t i = 0; i < table.size(); ++i) {
        table[i] = std::vector<int>(obstacleGrid[i].size(), 0);
    }

    if (obstacleGrid[0][0] != 1) {
        table[0][0] = 1;
    }
    for (size_t i = 0; i < obstacleGrid.size(); ++i) {
        for (size_t j = 0; j < obstacleGrid[i].size(); ++j) {
            if (table[i][j] != 0 || obstacleGrid[i][j] == 1) {
                continue;
            }

            int val = 0;
            if (i >= 1) {
                val += table[i - 1][j];
            }
            if (j >= 1) {
                val += table[i][j - 1];
            }

            table[i][j] = val;
        }
    }

    return table.back().back();
}

int main() {
    {
        // clang-format off
        std::vector<std::vector<int>> input {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0},
        };
        // clang-format on
        assert(uniquePathsWithObstacles(input) == 2);
    }
    {
        // clang-format off
        std::vector<std::vector<int>> input {
            {0, 1},
            {0, 0},
        };
        // clang-format on
        assert(uniquePathsWithObstacles(input) == 1);
    }
    {
        // clang-format off
        std::vector<std::vector<int>> input {
            {1},
        };
        // clang-format on
        assert(uniquePathsWithObstacles(input) == 0);
    }
    return 0;
}
