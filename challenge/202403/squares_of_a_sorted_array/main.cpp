#include <cassert>
#include <vector>
#include <cmath>

std::vector<int> sortedSquares(const std::vector<int> &nums) {
    int len = nums.size();
    std::vector<int> ret(len, 0);

    int left = 0;
    int right = len - 1;
    for (int i = len - 1; i >= 0; --i) {
        if (std::abs(nums[left]) < std::abs(nums[right])) {
            ret[i] = nums[right] * nums[right];
            --right;
        } else {
            ret[i] = nums[left] * nums[left];
            ++left;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{-4, -1, 0, 3, 10};
        std::vector<int> expected{0, 1, 9, 16, 100};
        auto ret = sortedSquares(nums);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{-7, -3, 2, 3, 11};
        std::vector<int> expected{4, 9, 9, 49, 121};
        auto ret = sortedSquares(nums);
        assert(ret == expected);
    }
    return 0;
}
