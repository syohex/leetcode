#include <cassert>
#include <vector>
#include <algorithm>

int maximalRectangle(const std::vector<std::vector<char>> &matrix) {
    if (matrix.empty()) {
        return 0;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

    std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));
    int ret = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == '1') {
                if (j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i][j - 1] + 1;
                }

                int width = dp[i][j];
                for (int k = i; k >= 0; k--) {
                    if (dp[k][j] == 0) {
                        break;
                    }

                    width = std::min(width, dp[k][j]);
                    ret = std::max(ret, width * (i - k + 1));
                }
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<char>> matrix{
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'},
        };
        assert(maximalRectangle(matrix) == 6);
    }
    {
        std::vector<std::vector<char>> matrix{};
        assert(maximalRectangle(matrix) == 0);
    }
    {
        std::vector<std::vector<char>> matrix{
            {'0'},
        };
        assert(maximalRectangle(matrix) == 0);
    }
    {
        std::vector<std::vector<char>> matrix{
            {'1'},
        };
        assert(maximalRectangle(matrix) == 1);
    }
    {
        std::vector<std::vector<char>> matrix{
            {'0', '0'},
        };
        assert(maximalRectangle(matrix) == 0);
    }
    return 0;
}