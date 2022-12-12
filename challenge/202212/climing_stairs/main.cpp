#include <cassert>
#include <vector>
#include <cstdio>

int climbStairs(int n) {
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        if (i >= 2) {
            dp[i] += dp[i - 2];
        }
    }

    return dp[n];
}

int main() {
    assert(climbStairs(1) == 1);
    assert(climbStairs(2) == 2);
    assert(climbStairs(3) == 3);
    assert(climbStairs(38) == 63245986);

    return 0;
}
