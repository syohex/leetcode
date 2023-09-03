#include <cassert>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>

int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
    std::vector<std::pair<int, int>> steps{{1, 0}, {0, 1}};
    std::deque<std::pair<int, int>> q;
    q.push_back({0, 0});
    dp[0][0] = 1;

    while (!q.empty()) {
        int len = q.size();

        for (int i = 0; i < len; ++i) {
            auto [row, col] = q.front();
            q.pop_front();

            for (const auto &[x, y] : steps) {
                int new_x = row + x;
                int new_y = col + y;

                if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) {
                    if (dp[new_x][new_y] == 0) {
                        q.push_back({new_x, new_y});
                    }
                    dp[new_x][new_y] += dp[row][col];
                }
            }
        }
    }

    return dp[m - 1][n - 1];
}

int uniquePaths2(int m, int n) {
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
    dp[0][0] = 1;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >= 1) {
                dp[i][j] += dp[i - 1][j];
            }
            if (j >= 1) {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }

    return dp[m - 1][n - 1];
}

int main() {
    assert(uniquePaths(3, 7) == 28);
    assert(uniquePaths(3, 2) == 3);
    assert(uniquePaths2(3, 7) == 28);
    assert(uniquePaths2(3, 2) == 3);
    return 0;
}
