#include <cassert>
#include <vector>
#include <cstdio>

int islandPerimeter(const std::vector<std::vector<int>> &grid) {
    int ret = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 0) {
                continue;
            }

            ret += 4;
            if (i >= 1 && grid[i - 1][j] == 1) {
                ret -= 2;
            }
            if (j >= 1 && grid[i][j - 1] == 1) {
                ret -= 2;
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> grid{
            {0, 1, 0, 0},
            {1, 1, 1, 0},
            {0, 1, 0, 0},
            {1, 1, 0, 0},
        };
        int ret = islandPerimeter(grid);
        assert(ret == 16);
    }
    {
        std::vector<std::vector<int>> grid{
            {1},
        };
        int ret = islandPerimeter(grid);
        assert(ret == 4);
    }
    {
        std::vector<std::vector<int>> grid{
            {1, 0},
        };
        int ret = islandPerimeter(grid);
        assert(ret == 4);
    }
    return 0;
}
