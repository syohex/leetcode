#include <cassert>
#include <vector>
#include <algorithm>

int rob(const std::vector<int> &nums) {
    int len = nums.size();
    std::vector<int> dp(len + 1, 0);
    dp[0] = 0;
    dp[1] = nums[0];

    for (int i = 1; i < len; ++i) {
        dp[i + 1] = std::max(dp[i], nums[i] + dp[i - 1]);
    }

    return dp[len];
}

int main() {
    {
        std::vector<int> nums{1, 2, 3, 1};
        assert(rob(nums) == 4);
    }
    {
        std::vector<int> nums{2, 7, 9, 3, 1};
        assert(rob(nums) == 12);
    }
    {
        std::vector<int> nums{42};
        assert(rob(nums) == 42);
    }
    return 0;
}