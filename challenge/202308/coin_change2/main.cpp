#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

int change(int amount, const std::vector<int> &coins) {
    std::vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int i = coin; i <= amount; ++i) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[amount];
}

int main() {
    {
        std::vector<int> coins{1, 2, 5};
        int ret = change(5, coins);
        assert(ret == 4);
    }
    {
        std::vector<int> coins{2};
        int ret = change(3, coins);
        assert(ret == 0);
    }
    {
        std::vector<int> coins{10};
        int ret = change(10, coins);
        assert(ret == 1);
    }
    return 0;
}
