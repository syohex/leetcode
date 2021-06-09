#include <cassert>
#include <vector>
#include <algorithm>
#include <climits>

int maxResult(const std::vector<int> &nums, int k) {
    int len = nums.size();
    std::vector<int> dp(len, INT_MIN);
    dp[0] = nums[0];

    for (int i = 0; i < len; ++i) {
        int end = std::min(len - 1, i + k);
        for (int j = i + 1; j <= end; ++j) {
            dp[j] = std::max(dp[j], dp[i] + nums[j]);
        }
    }

    return dp[len - 1];
}

int main() {
    {
        std::vector<int> nums{1, -1, -2, 4, -7, 3};
        assert(maxResult(nums, 2) == 7);
    }
    {
        std::vector<int> nums{10, -5, -2, 4, 0, 3};
        assert(maxResult(nums, 3) == 17);
    }
    {
        std::vector<int> nums{1, -5, -20, 4, -1, 3, -6, -3};
        assert(maxResult(nums, 2) == 0);
    }
    return 0;
}
