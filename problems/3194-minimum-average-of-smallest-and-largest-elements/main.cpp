#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

double minimumAverage(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    double ret = nums.back();
    int len = nums.size();
    for (int i = 0; i < len / 2; ++i) {
        ret = std::min(ret, (nums[i] + nums[len - 1 - i]) / 2.0);
    }
    return ret;
}

int main() {
    {
        std::vector<int> nums{7, 8, 3, 4, 15, 13, 4, 1};
        auto ret = minimumAverage(nums);
        assert(ret == 5.5);
    }
    {
        std::vector<int> nums{1, 9, 8, 3, 10, 5};
        auto ret = minimumAverage(nums);
        assert(ret == 5.5);
    }
    {
        std::vector<int> nums{1, 2, 3, 7, 8, 9};
        auto ret = minimumAverage(nums);
        assert(ret == 5.0);
    }
    return 0;
}
