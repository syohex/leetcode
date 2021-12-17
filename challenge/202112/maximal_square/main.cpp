#include <cassert>
#include <vector>
#include <algorithm>

int maximalSquare(const std::vector<std::vector<char>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        if (matrix[i][0] == '1') {
            dp[i][0] = 1;
        }
    }
    for (int i = 0; i < cols; ++i) {
        if (matrix[0][i] == '1') {
            dp[0][i] = 1;
        }
    }

    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (matrix[i][j] != '1') {
                continue;
            }

            if (matrix[i - 1][j - 1] == '0') {
                dp[i][j] = 1;
            } else {
                int limit = dp[i - 1][j - 1];
                int row_ones = 1;
                for (int m = 1; m <= limit && matrix[i - m][j] == '1'; ++m) {
                    ++row_ones;
                }

                int col_ones = 1;
                for (int m = 1; m <= limit && matrix[i][j - m] == '1'; ++m) {
                    ++col_ones;
                }

                dp[i][j] = std::min(row_ones, col_ones);
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            ret = std::max(ret, dp[i][j] * dp[i][j]);
        }
    }

    return ret;
}

int main() {
    {
        // clang-format off
        std::vector<std::vector<char>> matrix{
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
        };
        // clang-format on
        assert(maximalSquare(matrix) == 4);
    }
    {
        std::vector<std::vector<char>> matrix{{'0', '1'}, {'1', '0'}};
        assert(maximalSquare(matrix) == 1);
    }
    {
        std::vector<std::vector<char>> matrix{{'0'}};
        assert(maximalSquare(matrix) == 0);
    }
    {
        std::vector<std::vector<char>> matrix{{'0'}};
        assert(maximalSquare(matrix) == 0);
    }
    {
        // clang-format off
        std::vector<std::vector<char>> matrix{
            {'1', '1', '1', '1', '1', '1', '1', '1'},
            {'1', '1', '1', '1', '1', '1', '1', '0'},
            {'1', '1', '1', '1', '1', '1', '1', '0'},
            {'1', '1', '1', '1', '1', '0', '0', '0'},
            {'0', '1', '1', '1', '1', '0', '0', '0'}
        };
        // clang-format on
        assert(maximalSquare(matrix) == 16);
    }

    return 0;
}