#include <cassert>
#include <vector>
#include <algorithm>

int jump(const std::vector<int> &nums) {
    std::vector<int> dp(nums.size(), 0);

    int len = nums.size();
    for (int i = 0; i < len; ++i) {
        for (int j = 1; j <= nums[i] && i + j < len; ++j) {
            if (dp[i + j] == 0) {
                dp[i + j] = dp[i] + 1;
            } else {
                dp[i + j] = std::min(dp[i + j], dp[i] + 1);
            }
        }
    }

    return dp.back();
}

int main() {
    {
        std::vector<int> nums{2, 3, 1, 1, 4};
        assert(jump(nums) == 2);
    }
    {
        std::vector<int> nums{2, 3, 0, 1, 4};
        assert(jump(nums) == 2);
    }
    return 0;
}