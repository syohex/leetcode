#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> minSubsequence(std::vector<int> &nums) {
    if (nums.size() == 1) {
        return nums;
    }

    int sum = 0;
    for (const auto v : nums) {
        sum += v;
    }

    std::sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });

    std::vector<int> ret{nums[0]};
    int s = nums[0];
    if (s > sum - s) {
        return ret;
    }

    for (size_t i = 1; i < nums.size(); ++i) {
        s += nums[i];
        ret.push_back(nums[i]);
        if (s > sum - s) {
            return ret;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> input{4, 3, 10, 9, 8};
        auto ret = minSubsequence(input);
        assert((ret == std::vector<int>{10, 9}));
    }
    {
        std::vector<int> input{4, 4, 7, 6, 7};
        auto ret = minSubsequence(input);
        assert((ret == std::vector<int>{7, 7, 6}));
    }
    {
        std::vector<int> input{6};
        auto ret = minSubsequence(input);
        assert((ret == std::vector<int>{6}));
    }
    return 0;
}
