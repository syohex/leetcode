#include <cassert>
#include <vector>

int islandPerimeter(const std::vector<std::vector<int>> &grid) {
    int ret = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                ret += 4;
            }
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 0) {
                continue;
            }

            if (i + 1 < rows && grid[i + 1][j] == 1) {
                ret -= 2;
            }
            if (j + 1 < cols && grid[i][j + 1] == 1) {
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
        assert(islandPerimeter(grid) == 16);
    }
    {
        std::vector<std::vector<int>> grid{
            {1},
        };
        assert(islandPerimeter(grid) == 4);
    }
    {
        std::vector<std::vector<int>> grid{
            {1, 0},
        };
        assert(islandPerimeter(grid) == 4);
    }
    {
        std::vector<std::vector<int>> grid{
            {1, 1},
        };
        assert(islandPerimeter(grid) == 6);
    }
    return 0;
}