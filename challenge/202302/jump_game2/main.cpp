#include <cassert>
#include <vector>
#include <algorithm>

int jump(const std::vector<int> &nums) {
    int len = nums.size();
    std::vector<int> dp(len, len + 1);
    dp[0] = 0;

    for (int i = 0; i < len - 1; ++i) {
        for (int j = 1; j <= nums[i] && i + j < len; ++j) {
            dp[i + j] = std::min(dp[i + j], dp[i] + 1);
        }
    }

    return dp.back();
}

int main() {
    {
        std::vector<int> nums{2, 3, 1, 1, 4};
        int ret = jump(nums);
        assert(ret == 2);
    }
    {
        std::vector<int> nums{2, 3, 0, 1, 4};
        int ret = jump(nums);
        assert(ret == 2);
    }
    {
        std::vector<int> nums{9, 9, 9, 9, 9};
        int ret = jump(nums);
        assert(ret == 1);
    }
    return 0;
}
