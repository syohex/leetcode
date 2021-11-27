#include <cassert>
#include <vector>
#include <cstdio>

std::vector<int> productExceptSelf(const std::vector<int> &nums) {
    int len = nums.size();
    std::vector<int> left_acc(nums.size()), right_acc(nums.size());
    left_acc[0] = 1;
    right_acc[len - 1] = 1;

    for (int i = 1; i < len; ++i) {
        left_acc[i] = left_acc[i - 1] * nums[i - 1];
    }
    for (int i = len - 2; i >= 0; --i) {
        right_acc[i] = right_acc[i + 1] * nums[i + 1];
    }

    std::vector<int> ret;
    for (int i = 0; i < len; ++i) {
        ret.push_back(left_acc[i] * right_acc[i]);
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 2, 3, 4};
        std::vector<int> expected{24, 12, 8, 6};
        assert(productExceptSelf(nums) == expected);
    }
    {
        std::vector<int> nums{-1, 1, 0, -3, 3};
        std::vector<int> expected{0, 0, 9, 0, 0};
        assert(productExceptSelf(nums) == expected);
    }
    {
        std::vector<int> nums{0, 1, 0, -3, 3};
        std::vector<int> expected{0, 0, 0, 0, 0};
        assert(productExceptSelf(nums) == expected);
    }
    return 0;
}