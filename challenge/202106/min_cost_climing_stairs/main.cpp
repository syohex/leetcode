#include <cassert>
#include <vector>
#include <algorithm>

int minCostClimbingStairs(const std::vector<int> &cost) {
    int len = cost.size();
    std::vector<int> dp(len + 1, 0);
    for (int i = 2; i <= len; ++i) {
        int a = dp[i - 2] + cost[i - 2];
        int b = dp[i - 1] + cost[i - 1];
        if (a > b) {
            dp[i] = b;
        } else {
            dp[i] = a;
        }
    }

    return dp[len];
}

int main() {
    {
        std::vector<int> cost{10, 15, 20};
        assert(minCostClimbingStairs(cost) == 15);
    }
    {
        std::vector<int> cost{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
        assert(minCostClimbingStairs(cost) == 6);
    }
    return 0;
}
