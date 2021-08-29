#include <cassert>
#include <vector>
#include <algorithm>
#include <climits>

int minimumDifference(std::vector<int> &nums, int k) {
    if (k == 1) {
        return 0;
    }

    std::sort(nums.begin(), nums.end());

    int ret = INT_MAX;
    int len = nums.size();
    for (int i = 0; i < len - (k - 1); ++i) {
        ret = std::min(ret, nums[i + k - 1] - nums[i]);
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{90};
        assert(minimumDifference(nums, 1) == 0);
    }
    {
        std::vector<int> nums{9, 4, 1, 7};
        assert(minimumDifference(nums, 2) == 2);
    }
    {
        std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
        assert(minimumDifference(nums, 9) == 8);
    }
    return 0;
}
