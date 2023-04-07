#include <cassert>
#include <vector>
#include <functional>
#include <cstdio>

int numEnclaves(std::vector<std::vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    std::function<int(int row, int col)> f;
    f = [&](int row, int col) -> int {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            return -1;
        }
        if (grid[row][col] == 0) {
            return 0;
        }

        grid[row][col] = 0;

        int ret = 1;
        bool ok = true;

        std::vector<std::pair<int, int>> steps{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (const auto &[x, y] : steps) {
            int r = row + x;
            int c = col + y;

            int lands = f(r, c);
            if (lands == -1) {
                ok = false;
            } else {
                ret += lands;
            }
        }

        return ok ? ret : -1;
    };

    int ret = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                int lands = f(i, j);
                if (lands > 0) {
                    ret += lands;
                }
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> grid{
            {0, 0, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0},
        };
        int ret = numEnclaves(grid);
        assert(ret == 3);
    }
    {
        std::vector<std::vector<int>> grid{
            {0, 1, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0},
        };
        int ret = numEnclaves(grid);
        assert(ret == 0);
    }
    {
        std::vector<std::vector<int>> grid {
            {0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
            {1, 1, 0, 0, 0, 1, 0, 1, 1, 1},
            {0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
            {0, 1, 1, 0, 0, 0, 1, 0, 1, 0},
            {0, 1, 1, 1, 1, 1, 0, 0, 1, 0},
            {0, 0, 1, 0, 1, 1, 1, 1, 0, 1},
            {0, 1, 1, 0, 0, 0, 1, 1, 1, 1},
            {0, 0, 1, 0, 0, 1, 0, 1, 0, 1},
            {1, 0, 1, 0, 1, 1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 1, 0, 0, 0, 1}
        };
        int ret = numEnclaves(grid);
        assert(ret == 3);
    }
    return 0;
}
