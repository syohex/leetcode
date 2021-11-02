#include <cassert>
#include <vector>
#include <functional>

int uniquePathsIII(std::vector<std::vector<int>> &grid) {
    int ret = 0;
    int start_row = 0;
    int start_col = 0;
    int remains = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                start_row = i;
                start_col = j;
            }
            if (grid[i][j] != -1) {
                ++remains;
            }
        }
    }

    std::vector<std::vector<int>> steps{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    std::function<void(int row, int col, int remains)> f;
    f = [&](int row, int col, int remains) {
        if (grid[row][col] == 2 && remains == 1) {
            ++ret;
            return;
        }

        int orig = grid[row][col];
        grid[row][col] = -2; // visited

        for (const auto &step : steps) {
            int new_row = row + step[0];
            int new_col = col + step[1];

            if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols && grid[new_row][new_col] >= 0) {
                f(new_row, new_col, remains - 1);
            }
        }

        grid[row][col] = orig;
    };

    f(start_row, start_col, remains);
    return ret;
}

int main() {
    {
        // clang-format off
        std::vector<std::vector<int>> grid {
            {1, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 2, -1},
        };
        // clang-format on
        assert(uniquePathsIII(grid) == 2);
    }
    {
        // clang-format off
        std::vector<std::vector<int>> grid {
            {1, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 2},
        };
        // clang-format on
        assert(uniquePathsIII(grid) == 4);
    }
    return 0;
}