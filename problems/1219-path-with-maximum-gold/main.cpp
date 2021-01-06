#include <cassert>
#include <vector>
#include <functional>

int getMaximumGold(std::vector<std::vector<int>> &grid) {
    std::function<int(int row, int col)> f;
    f = [&f, &grid](int row, int col) {
        int orig = grid[row][col];
        grid[row][col] = 0;

        int rs[] = {0, 0, 1, -1};
        int cs[] = {1, -1, 0, 0};
        int row_limit = grid.size();
        int col_limit = grid[row].size();
        int ret = 0;
        for (int i = 0; i < 4; ++i) {
            int r = row + rs[i];
            int c = col + cs[i];
            if (r >= 0 && r < row_limit && c >= 0 && c < col_limit && grid[r][c] > 0) {
                ret = std::max(ret, f(r, c));
            }
        }

        grid[row][col] = orig;
        return orig + ret;
    };

    int ret = 0;
    for (int i = 0; i < static_cast<int>(grid.size()); ++i) {
        for (int j = 0; j < static_cast<int>(grid[i].size()); ++j) {
            if (grid[i][j] > 0) {
                ret = std::max(ret, f(i, j));
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> grid{
            {0, 6, 0},
            {5, 8, 7},
            {0, 9, 0},
        };
        assert(getMaximumGold(grid) == 24);
    }
    {
        std::vector<std::vector<int>> grid{
            {1, 0, 7}, {2, 0, 6}, {3, 4, 5}, {0, 3, 0}, {9, 0, 20},
        };
        assert(getMaximumGold(grid) == 28);
    }
    return 0;
}
