#include <cassert>
#include <vector>
#include <algorithm>

int coinChange(const std::vector<int> &coins, int amount) {
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
    assert((coinChange(std::vector<int>{1, 2, 5}, 11) == 3));
    assert((coinChange(std::vector<int>{2}, 11) == -1));
    assert((coinChange(std::vector<int>{0}, 0) == 0));
    assert((coinChange(std::vector<int>{1}, 1) == 1));
    assert((coinChange(std::vector<int>{1}, 2) == 2));
    assert((coinChange(std::vector<int>{1}, 11) == 11));
    return 0;
}
