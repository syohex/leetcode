#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

int lengthOfLIS(const std::vector<int> &nums) {
    int len = nums.size();
    std::vector<int> dp(len, 1);

    int ret = 1;
    for (int i = 1; i < len; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
                ret = std::max(ret, dp[i]);
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
        int ret = lengthOfLIS(nums);
        assert(ret == 4);
    }
    {
        std::vector<int> nums{0, 1, 0, 3, 2, 3};
        int ret = lengthOfLIS(nums);
        assert(ret == 4);
    }
    {
        std::vector<int> nums{7, 7, 7, 7, 7, 7, 7};
        int ret = lengthOfLIS(nums);
        assert(ret == 1);
    }
    {
        std::vector<int> nums{3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12};
        int ret = lengthOfLIS(nums);
        assert(ret == 6);
    }
    return 0;
}
