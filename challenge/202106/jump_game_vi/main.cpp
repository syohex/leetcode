#include <cassert>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

int maxResult(const std::vector<int> &nums, int k) {
    int len = nums.size();
    std::vector<int> dp(len, INT_MIN);
    dp[0] = nums[0];

    std::priority_queue<std::pair<int, int>> q;
    q.push(std::make_pair(nums[0], 0));

    for (int i = 1; i < len; ++i) {
        while (q.top().second < i - k) {
            q.pop();
        }

        dp[i] = nums[i] + dp[q.top().second];
        q.push(std::make_pair(dp[i], i));
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
