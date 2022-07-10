#include <cassert>
#include <vector>
#include <algorithm>

int minCostClimbingStairs(const std::vector<int> &cost) {
    int prev2 = cost[0];
    int prev1 = cost[1];

    for (size_t i = 2; i < cost.size(); ++i) {
        int val2 = cost[i] + prev2;
        int val1 = cost[i] + prev1;

        prev2 = prev1;
        prev1 = std::min(val1, val2);
    }

    return std::min(prev1, prev2);
}

int main() {
    {
        std::vector<int> cost{10, 15, 20};
        int ret = minCostClimbingStairs(cost);
        assert(ret == 15);
    }
    {
        std::vector<int> cost{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
        int ret = minCostClimbingStairs(cost);
        assert(ret == 6);
    }
    return 0;
}
