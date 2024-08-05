#include <cassert>
#include <vector>
#include <queue>

int rangeSum(const std::vector<int> &nums, int n, int left, int right) {
    using Data = std::pair<int, int>;

    int len = nums.size();
    std::priority_queue<Data, std::vector<Data>, std::greater<Data>> q;
    for (int i = 0; i < len; ++i) {
        q.push({nums[i], i});
    }

    int ret = 0;
    int mod = 1'000'000'007;
    for (int i = 1; i <= right; ++i) {
        auto [sum, index] = q.top();
        q.pop();

        if (i >= left) {
            ret = (ret + sum) % mod;
        }

        if (index < len - 1) {
            q.push({sum + nums[index + 1], index + 1});
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 2, 3, 4};
        int ret = rangeSum(nums, 4, 1, 5);
        assert(ret == 13);
    }
    {
        std::vector<int> nums{1, 2, 3, 4};
        int ret = rangeSum(nums, 4, 3, 4);
        assert(ret == 6);
    }
    {
        std::vector<int> nums{1, 2, 3, 4};
        int ret = rangeSum(nums, 4, 1, 10);
        assert(ret == 50);
    }
    return 0;
}