#include <cassert>
#include <vector>

int matrixScore(std::vector<std::vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; ++i) {
        if (grid[i][0] == 0) {
            for (int j = 0; j < cols; ++j) {
                grid[i][j] = grid[i][j] == 0 ? 1 : 0;
            }
        }
    }

    for (int j = 1; j < cols; ++j) {
        int sum = 0;
        for (int i = 0; i < rows; ++i) {
            sum += grid[i][j];
        }
        if (sum < rows - sum) {
            for (int i = 0; i < rows; ++i) {
                grid[i][j] = grid[i][j] == 0 ? 1 : 0;
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < rows; ++i) {
        int sum = 0;
        for (int j = 0; j < cols; ++j) {
            sum = sum * 2 + grid[i][j];
        }
        ret += sum;
    }
    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> grid{
            {0, 0, 1, 1},
            {1, 0, 1, 0},
            {1, 1, 0, 0},
        };
        int ret = matrixScore(grid);
        assert(ret == 39);
    }
    {
        std::vector<std::vector<int>> grid{
            {0},
        };
        int ret = matrixScore(grid);
        assert(ret == 1);
    }
    return 0;
}
