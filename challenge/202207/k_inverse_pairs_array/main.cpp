#include <cassert>
#include <functional>
#include <algorithm>
#include <cstdint>
#include <cstring>
#include <vector>

int kInversePairs(int n, int k) {
    constexpr std::int64_t MOD = 1'000'000'007;
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (j == 0) {
                dp[i][j] = 1;
            } else {
                int len = std::min(i - 1, j);
                for (int k = 0; k <= len; ++k) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
                }
            }
        }
    }

    return dp[n][k];
}

int main() {
    assert(kInversePairs(3, 0) == 1);
    assert(kInversePairs(3, 1) == 2);
    return 0;
}
