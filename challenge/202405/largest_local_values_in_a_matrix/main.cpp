#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

std::vector<std::vector<int>> largestLocal(const std::vector<std::vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    std::vector<std::vector<int>> ret(rows - 2, std::vector<int>(cols - 2, 0));
    for (int i = 0; i < rows - 2; ++i) {
        for (int j = 0; j < cols - 2; ++j) {
            int v = 0;
            for (int x = 0; x < 3; ++x) {
                for (int y = 0; y < 3; ++y) {
                    v = std::max(v, grid[i + x][j + y]);
                }
            }
            ret[i][j] = v;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> grid{
            {9, 9, 8, 1},
            {5, 6, 2, 6},
            {8, 2, 6, 4},
            {6, 2, 2, 2},
        };
        std::vector<std::vector<int>> expected{
            {9, 9},
            {8, 6},
        };
        auto ret = largestLocal(grid);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> grid{
            {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 2, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1},
        };
        std::vector<std::vector<int>> expected{
            {2, 2, 2},
            {2, 2, 2},
            {2, 2, 2},
        };
        auto ret = largestLocal(grid);
        assert(ret == expected);
    }

    return 0;
}
