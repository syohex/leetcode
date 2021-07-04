#include <cassert>
#include <vector>

int countVowelPermutation(int n) {
    constexpr long MOD = 1'000'000'007;
    // index a=0, e=1, i=2, o=3, u=4
    std::vector<std::vector<long>> dp(5, std::vector<long>(n));
    for (int i = 0; i < 5; ++i) {
        dp[i][0] = 1;
    }

    for (int i = 1; i < n; ++i) {
        dp[0][i] = (dp[1][i - 1] + dp[2][i - 1] + dp[4][i - 1]) % MOD;
        dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % MOD;
        dp[2][i] = (dp[1][i - 1] + dp[3][i - 1]) % MOD;
        dp[3][i] = dp[2][i - 1];
        dp[4][i] = (dp[2][i - 1] + dp[3][i - 1]) % MOD;
    }

    long ret = 0;
    for (int i = 0; i < 5; ++i) {
        ret += dp[i][n - 1];
    }

    return ret % MOD;
}

int main() {
    assert(countVowelPermutation(1) == 5);
    assert(countVowelPermutation(2) == 10);
    assert(countVowelPermutation(5) == 68);
    return 0;
}