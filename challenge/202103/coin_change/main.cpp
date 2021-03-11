#include <cassert>
#include <vector>

int coinChange(std::vector<int> &coins, int amount) {
    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i >= coin) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] == amount + 1 ? -1 : dp[amount];
}

int main() {
    {
        std::vector<int> coins{1, 2, 5};
        assert(coinChange(coins, 11) == 3);
    }
    {
        std::vector<int> coins{2};
        assert(coinChange(coins, 3) == -1);
    }
    {
        std::vector<int> coins{1};
        assert(coinChange(coins, 0) == 0);
    }
    {
        std::vector<int> coins{1};
        assert(coinChange(coins, 1) == 1);
    }
    {
        std::vector<int> coins{1};
        assert(coinChange(coins, 2) == 2);
    }
    {
        std::vector<int> coins{186, 419, 83, 408};
        assert(coinChange(coins, 6249) == 20);
    }
    return 0;
}
