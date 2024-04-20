#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstdio>

std::vector<std::vector<int>> findFarmland(std::vector<std::vector<int>> &land) {
    int rows = land.size();
    int cols = land[0].size();

    std::function<void(int row, int col, int &max_row, int &max_col)> f;
    f = [&](int row, int col, int &max_row, int &max_col) {
        land[row][col] = 0;

        max_row = std::max(max_row, row);
        max_col = std::max(max_col, col);

        if (row + 1 < rows && land[row + 1][col] == 1) {
            f(row + 1, col, max_row, max_col);
        }
        if (col + 1 < cols && land[row][col + 1] == 1) {
            f(row, col + 1, max_row, max_col);
        }
    };

    std::vector<std::vector<int>> ret;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (land[i][j] == 1) {
                int max_row = -1;
                int max_col = -1;
                f(i, j, max_row, max_col);
                ret.push_back({i, j, max_row, max_col});
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> land{
            {1, 0, 0},
            {0, 1, 1},
            {0, 1, 1},
        };
        std::vector<std::vector<int>> expected{
            {0, 0, 0, 0},
            {1, 1, 2, 2},
        };
        auto ret = findFarmland(land);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> land{
            {1, 1},
            {1, 1},
        };
        std::vector<std::vector<int>> expected{
            {0, 0, 1, 1},
        };
        auto ret = findFarmland(land);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> land{
            {0},
        };
        auto ret = findFarmland(land);
        assert(ret.empty());
    }
    return 0;
}
