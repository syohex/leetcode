#include <cassert>
#include <vector>

int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
    dp[0][0] = 1;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }

            if (j >= 1) {
                dp[i][j] += dp[i][j - 1];
            }
            if (i >= 1) {
                dp[i][j] += dp[i - 1][j];
            }
        }
    }

    return dp[m - 1][n - 1];
}

int main() {
    assert(uniquePaths(3, 7) == 28);
    assert(uniquePaths(3, 2) == 3);
    assert(uniquePaths(7, 3) == 28);
    return 0;
}
