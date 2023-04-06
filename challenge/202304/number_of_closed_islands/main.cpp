#include <cassert>
#include <vector>
#include <functional>
#include <cstdio>

int closedIsland(std::vector<std::vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    std::function<bool(int row, int col)> f;
    f = [&](int row, int col) -> bool {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            return false;
        }
        if (grid[row][col] == 1) {
            return true;
        }

        grid[row][col] = 1;

        std::vector<std::pair<int, int>> steps{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        bool ok = true;
        for (const auto &[x, y] : steps) {
            if (!f(row + x, col + y)) {
                ok = false;
            }
        }

        return ok;
    };

    int ret = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] != 0) {
                continue;
            }
            if (f(i, j)) {
                ret += 1;
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> grid{
            {1, 1, 1, 1, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 1, 1, 0}, {1, 0, 1, 0, 1, 1, 1, 0},
            {1, 0, 0, 0, 0, 1, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 0},
        };
        int ret = closedIsland(grid);
        assert(ret == 2);
    }
    {
        std::vector<std::vector<int>> grid{
            {0, 0, 1, 0, 0},
            {0, 1, 0, 1, 0},
            {0, 1, 1, 1, 0},
        };
        int ret = closedIsland(grid);
        assert(ret == 1);
    }
    {
        std::vector<std::vector<int>> grid{
            {1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 1}, {1, 0, 1, 1, 1, 0, 1}, {1, 0, 1, 0, 1, 0, 1},
            {1, 0, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1},
        };
        int ret = closedIsland(grid);
        assert(ret == 2);
    }
    {
        std::vector<std::vector<int>> grid{
            {0, 0, 1, 1, 0, 1, 0, 0, 1, 0}, {1, 1, 0, 1, 1, 0, 1, 1, 1, 0}, {1, 0, 1, 1, 1, 0, 0, 1, 1, 0},
            {0, 1, 1, 0, 0, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 0, 0, 1, 1, 1, 0}, {0, 1, 0, 1, 0, 1, 0, 1, 1, 1},
            {1, 0, 1, 0, 1, 1, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 1, 0, 1, 0, 1},
            {1, 1, 1, 0, 1, 1, 0, 1, 1, 0},
        };
        int ret = closedIsland(grid);
        assert(ret == 5);
    }
    return 0;
}
