#include <cassert>
#include <vector>
#include <queue>
#include <cstddef>
#include <cstdio>

int maxResult(const std::vector<int> &nums, int k) {
    struct Data {
        int score;
        int pos;

        bool operator<(const Data &o) const {
            if (score == o.score) {
                return pos < o.pos;
            }

            return score < o.score;
        }
    };

    int len = nums.size();
    std::vector<int> dp(len, 0);
    dp[0] = nums[0];

    std::priority_queue<Data, std::vector<Data>> q;
    q.push({nums[0], 0});

    for (int i = 1; i < len; ++i) {
        while (q.top().pos < i - k) {
            q.pop();
        }

        dp[i] = nums[i] + dp[q.top().pos];
        q.push({dp[i], i});
    }

    return dp.back();
}

int main() {
    {
        std::vector<int> nums{1, -1, -2, 4, -7, 3};
        int ret = maxResult(nums, 2);
        assert(ret == 7);
    }
    {
        std::vector<int> nums{10, -5, -2, 4, 0, 3};
        int ret = maxResult(nums, 3);
        assert(ret == 17);
    }
    {
        std::vector<int> nums{1, -5, -20, 4, -1, 3, -6, -3};
        int ret = maxResult(nums, 2);
        assert(ret == 0);
    }
    return 0;
}
