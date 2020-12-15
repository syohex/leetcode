#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> sortedSquares(std::vector<int> &nums) {
    for (size_t i = 0; i < nums.size(); ++i) {
        nums[i] = nums[i] * nums[i];
    }

    std::sort(nums.begin(), nums.end());
    return nums;
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
