#include <cassert>
#include <vector>
#include <algorithm>

int maxSubArray(const std::vector<int> &nums) {
    int sum = nums[0];
    int ret = sum;
    for (size_t i = 1; i < nums.size(); ++i) {
        int tmp = sum + nums[i];
        if (tmp > nums[i]) {
            ret = std::max(ret, tmp);
            sum = tmp;
        } else {
            ret = std::max(ret, nums[i]);
            sum = nums[i];
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, -4};
        assert(maxSubArray(nums) == 6);
    }
    {
        std::vector<int> nums{1};
        assert(maxSubArray(nums) == 1);
    }
    {
        std::vector<int> nums{0};
        assert(maxSubArray(nums) == 0);
    }
    {
        std::vector<int> nums{-1};
        assert(maxSubArray(nums) == -1);
    }
    {
        std::vector<int> nums{-2147483647};
        assert(maxSubArray(nums) == -2147483647);
    }
    return 0;
}
