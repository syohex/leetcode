#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

std::vector<int> largestDivisibleSubset(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    int len = nums.size();
    std::vector<int> dp(len, 1);

    int max_len = 1;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                max_len = std::max(max_len, dp[i]);
            }
        }
    }

    int prev = -1;
    std::vector<int> ret(max_len);
    for (int i = len - 1; i >= 0; --i) {
        if (max_len == dp[i] && (prev == -1 || prev % nums[i] == 0)) {
            ret[max_len - 1] = nums[i];
            --max_len;
            prev = nums[i];
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 2, 3};
        std::vector<int> expected{1, 3};
        auto ret = largestDivisibleSubset(nums);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{1, 2, 4, 8};
        std::vector<int> expected{1, 2, 4, 8};
        auto ret = largestDivisibleSubset(nums);
        assert(ret == expected);
    }
    return 0;
}
