#include <cassert>
#include <vector>
#include <algorithm>

int lengthOfLIS(const std::vector<int> &nums) {
    std::vector<int> dp(nums.size(), 1);

    int ret = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }

        ret = std::max(ret, dp[i]);
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
        assert(lengthOfLIS(nums) == 4);
    }
    {
        std::vector<int> nums{0, 1, 0, 3, 2, 3};
        assert(lengthOfLIS(nums) == 4);
    }
    {
        std::vector<int> nums{7, 7, 7, 7, 7, 7, 7};
        assert(lengthOfLIS(nums) == 1);
    }
    return 0;
}
