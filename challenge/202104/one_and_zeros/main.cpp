#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

int findMaxForm(const std::vector<std::string> &strs, int m, int n) {
    std::vector<std::vector<int>> v(strs.size(), std::vector<int>(2, 0));
    for (size_t i = 0; i < strs.size(); ++i) {
        for (int c : strs[i]) {
            ++v[i][c - '0'];
        }
    }

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for (const auto &d : v) {
        for (int i = m; i >= d[0]; --i) {
            for (int j = n; j >= d[1]; --j) {
                dp[i][j] = std::max(dp[i][j], dp[i - d[0]][j - d[1]] + 1);
            }
        }
    }

    return dp[m][n];
}

int main() {
    {
        std::vector<std::string> strs{"10", "0001", "111001", "1", "0"};
        assert(findMaxForm(strs, 5, 3) == 4);
    }
    {
        std::vector<std::string> strs{"10", "1", "0"};
        assert(findMaxForm(strs, 1, 1) == 2);
    }
    return 0;
}
