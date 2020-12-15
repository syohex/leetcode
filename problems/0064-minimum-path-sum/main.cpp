#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

int minPathSum(const std::vector<std::vector<int>> &grid) {
    std::vector<std::vector<int>> distances(grid.size());
    for (size_t i = 0; i < grid.size(); ++i) {
        distances[i] = std::vector<int>(grid[i].size(), -1);
    }

    distances[0][0] = grid[0][0];
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[i].size(); ++j) {
            if (distances[i][j] != -1) {
                continue;
            }

            if (i == 0) {
                distances[i][j] = grid[i][j] + distances[i][j - 1];
            } else if (j == 0) {
                distances[i][j] = grid[i][j] + distances[i - 1][j];
            } else {
                int min = std::min(distances[i - 1][j], distances[i][j - 1]);
                distances[i][j] = grid[i][j] + min;
            }
        }
    }

    return distances.back().back();
}

int main() {
    {
        std::vector<std::vector<int>> grid{
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1},
        };
        assert(minPathSum(grid) == 7);
    }
    {
        std::vector<std::vector<int>> grid{
            {1, 2, 3},
            {4, 5, 6},
        };
        assert(minPathSum(grid) == 12);
    }
    {
        std::vector<std::vector<int>> grid{
            {0},
        };
        assert(minPathSum(grid) == 0);
    }
    return 0;
}
