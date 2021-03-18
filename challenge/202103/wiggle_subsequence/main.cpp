#include <cassert>
#include <vector>
#include <algorithm>

int wiggleMaxLength(const std::vector<int> &nums) {
    int ret = 1;
    int prev_diff = 0;
    for (size_t i = 1; i < nums.size(); ++i) {
        int diff = nums[i] - nums[i - 1];
        if ((diff > 0 && prev_diff <= 0) || (diff < 0 && prev_diff >= 0)) {
            ++ret;
            prev_diff = diff;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 7, 4, 9, 2, 5};
        assert(wiggleMaxLength(nums) == 6);
    }
    {
        std::vector<int> nums{1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
        assert(wiggleMaxLength(nums) == 7);
    }
    {
        std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
        assert(wiggleMaxLength(nums) == 2);
    }
    {
        std::vector<int> nums{1, 1, 1, 1, 1, 1, 1};
        assert(wiggleMaxLength(nums) == 1);
    }
    {
        std::vector<int> nums{1, 2, 2, 2, 2, 3};
        assert(wiggleMaxLength(nums) == 2);
    }
    return 0;
}
