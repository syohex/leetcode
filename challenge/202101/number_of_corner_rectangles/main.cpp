#include <cassert>
#include <vector>

int countCornerRectangles(const std::vector<std::vector<int>> &grid) {
    if (grid.size() <= 1) {
        return 0;
    }

    int ret = 0;
    int row_len = grid.size();
    int col_len = grid[0].size();
    for (int i = 0; i < row_len; ++i) {
        for (int j = 0; j < col_len; ++j) {
            if (grid[i][j] == 1) {
                for (int k = j + 1; k < col_len; ++k) {
                    if (grid[i][k] == 1) {
                        for (int m = i + 1; m < row_len; ++m) {
                            if (grid[m][k] == 1 && grid[m][j] == 1) {
                                ++ret;
                            }
                        }
                    }
                }
            }
        }
    }

    return ret;
}

int main() {
    {
        // clang-format off
        std::vector<std::vector<int>> input {
            {1, 0, 0, 1, 0},
            {0, 0, 1, 0, 1},
            {0, 0, 0, 1, 0},
            {1, 0, 1, 0, 1},
        };
        // clang-format on

        assert(countCornerRectangles(input) == 1);
    }
    {
        // clang-format off
        std::vector<std::vector<int>> input {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1},
        };
        // clang-format on

        assert(countCornerRectangles(input) == 9);
    }
    {
        // clang-format off
        std::vector<std::vector<int>> input {
            {1, 1, 1, 1},
        };
        // clang-format on

        assert(countCornerRectangles(input) == 0);
    }

    return 0;
}
