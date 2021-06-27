#include <cassert>
#include <vector>
#include <algorithm>

int maxProductDifference(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    int len = nums.size();
    return nums[len - 1] * nums[len - 2] - nums[1] * nums[0];
}

int main() {
    {
        std::vector<int> nums{5, 6, 2, 7, 4};
        assert(maxProductDifference(nums) == 34);
    }
    {
        std::vector<int> nums{4, 2, 5, 9, 7, 4, 8};
        assert(maxProductDifference(nums) == 64);
    }
    return 0;
}
