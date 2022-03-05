#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <limits>

int deleteAndEarn(const std::vector<int> &nums) {
    if (nums.size() <= 1) {
        return nums[0];
    }

    std::map<int, int> m;
    int limit = std::numeric_limits<int>::min();
    for (int num : nums) {
        ++m[num];
        limit = std::max(limit, num);
    }

    std::vector<int> dp(limit + 1, 0);
    dp[0] = 0;
    dp[1] = m[1];
    for (int i = 2; i <= limit; ++i) {
        int val = i * m[i];
        dp[i] = std::max(dp[i - 1], dp[i - 2] + val);
    }

    return dp.back();
}

int main() {
    {
        std::vector<int> nums{3, 4, 2};
        assert(deleteAndEarn(nums) == 6);
    }
    {
        std::vector<int> nums{2, 2, 3, 3, 3, 4};
        assert(deleteAndEarn(nums) == 9);
    }
    {
        std::vector<int> nums{3, 1};
        assert(deleteAndEarn(nums) == 4);
    }
    return 0;
}
