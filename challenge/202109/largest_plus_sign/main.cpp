#include <cassert>
#include <vector>
#include <algorithm>

int orderOfLargestPlusSign(int n, const std::vector<std::vector<int>> &mines) {
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 1));
    for (const auto &mine : mines) {
        matrix[mine[0]][mine[1]] = 0;
    }

    int ret = 0;
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) {
                ++count;
            } else {
                count = 0;
            }

            dp[i][j] = count;
        }

        count = 0;
        for (int j = n - 1; j >= 0; --j) {
            if (matrix[i][j] == 1) {
                ++count;
            } else {
                count = 0;
            }

            dp[i][j] = std::min(dp[i][j], count);
        }
    }

    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (matrix[j][i] == 1) {
                ++count;
            } else {
                count = 0;
            }

            dp[j][i] = std::min(dp[j][i], count);
        }

        count = 0;
        for (int j = n - 1; j >= 0; --j) {
            if (matrix[j][i] == 1) {
                ++count;
            } else {
                count = 0;
            }

            dp[j][i] = std::min(dp[j][i], count);
            ret = std::max(ret, dp[j][i]);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> mines{{4, 2}};
        assert(orderOfLargestPlusSign(5, mines) == 2);
    }
    {
        std::vector<std::vector<int>> mines{{0, 0}};
        assert(orderOfLargestPlusSign(1, mines) == 0);
    }
    {
        std::vector<std::vector<int>> mines{{0, 2}, {0, 4}, {1, 2}, {2, 0}, {2, 3}, {2, 4}, {3, 4}, {4, 2}, {4, 4}};
        assert(orderOfLargestPlusSign(5, mines) == 2);
    }
    return 0;
}
