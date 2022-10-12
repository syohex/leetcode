#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

int maxSum(const std::vector<std::vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    int ret = 0;
    for (int i = 0; i < rows - 2; ++i) {
        for (int j = 0; j < cols - 2; ++j) {
            int sum = 0;
            for (int x = 0; x < 3; ++x) {
                for (int y = 0; y < 3; ++y) {
                    if ((x == 1 && y == 0) || (x == 1 && y == 2)) {
                        continue;
                    }

                    sum += grid[i + x][j + y];
                }
            }

            ret = std::max(ret, sum);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> grid{
            {6, 2, 1, 3},
            {4, 2, 1, 5},
            {9, 2, 8, 7},
            {4, 1, 2, 9},
        };
        int ret = maxSum(grid);
        assert(ret == 30);
    }
    {
        std::vector<std::vector<int>> grid{
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
        };
        int ret = maxSum(grid);
        assert(ret == 35);
    }
    return 0;
}
