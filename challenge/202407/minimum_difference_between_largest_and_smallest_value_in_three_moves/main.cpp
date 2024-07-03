#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>

int minDifference(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    if (nums.size() <= 4) {
        return 0;
    }

    int ret = std::numeric_limits<int>::max();
    int j = nums.size() - 4;

    for (int i = 0; i < 4; ++i) {
        ret = std::min(ret, nums[j + i] - nums[i]);
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{5, 3, 2, 4};
        int ret = minDifference(nums);
        assert(ret == 0);
    }
    {
        std::vector<int> nums{1, 5, 0, 10, 14};
        int ret = minDifference(nums);
        assert(ret == 1);
    }
    {
        std::vector<int> nums{3, 100, 20};
        int ret = minDifference(nums);
        assert(ret == 0);
    }
    return 0;
}
