#include <cassert>
#include <vector>

int combinationSum4(const std::vector<int> &nums, int target) {
    std::vector<unsigned long> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; ++i) {
        for (int num : nums) {
            if (i - num >= 0) {
                dp[i] += dp[i - num];
            }
        }
    }

    return dp[target];
}

int main() {
    {
        std::vector<int> nums{1, 2, 3};
        assert(combinationSum4(nums, 4) == 7);
    }
    {
        std::vector<int> nums{9};
        assert(combinationSum4(nums, 3) == 0);
    }
    {
        std::vector<int> nums{3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
        assert(combinationSum4(nums, 10) == 9);
    }
    return 0;
}
