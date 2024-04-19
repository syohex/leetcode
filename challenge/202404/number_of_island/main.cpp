#include <cassert>
#include <vector>
#include <functional>

int numIsLands(std::vector<std::vector<char>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    std::function<void(int row, int col)> f;
    f = [&](int row, int col) {
        grid[row][col] = 0;

        if (row >= 1 && grid[row - 1][col] == '1') {
            f(row - 1, col);
        }
        if (row + 1 < rows && grid[row + 1][col] == '1') {
            f(row + 1, col);
        }
        if (col >= 1 && grid[row][col - 1] == '1') {
            f(row, col - 1);
        }
        if (col + 1 < cols && grid[row][col + 1] == '1') {
            f(row, col + 1);
        }
    };

    int ret = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == '1') {
                ++ret;
                f(i, j);
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<char>> grid{
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'},
        };
        int ret = numIsLands(grid);
        assert(ret == 1);
    }
    {
        std::vector<std::vector<char>> grid{
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'},
        };
        int ret = numIsLands(grid);
        assert(ret == 3);
    }
    return 0;
}
