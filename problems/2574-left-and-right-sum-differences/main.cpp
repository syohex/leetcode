#include <cassert>
#include <vector>
#include <cmath>
#include <cstdio>

std::vector<int> leftRightDifferences(const std::vector<int> &nums) {
    int len = nums.size();
    std::vector<int> left_sum(len, 0), right_sum(len, 0);
    left_sum[0] = 0;
    right_sum[len - 1] = 0;

    int sum = nums[0];
    for (int i = 1; i < len; ++i) {
        left_sum[i] = sum;
        sum += nums[i];
    }

    sum = nums.back();
    for (int i = len - 2; i >= 0; --i) {
        right_sum[i] = sum;
        sum += nums[i];
    }

    std::vector<int> ret(len, 0);
    for (int i = 0; i < len; ++i) {
        ret[i] = std::abs(left_sum[i] - right_sum[i]);
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{10, 4, 8, 3};
        std::vector<int> expected{15, 1, 11, 22};
        auto ret = leftRightDifferences(nums);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{1};
        std::vector<int> expected{0};
        auto ret = leftRightDifferences(nums);
        assert(ret == expected);
    }
    return 0;
}
