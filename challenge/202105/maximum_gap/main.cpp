#include <cassert>
#include <vector>
#include <algorithm>

int maximumCap(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    int ret = 0;
    for (size_t i = 1; i < nums.size(); ++i) {
        ret = std::max(ret, nums[i] - nums[i - 1]);
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{3, 6, 9, 1};
        assert(maximumCap(nums) == 3);
    }
    {
        std::vector<int> nums{10};
        assert(maximumCap(nums) == 0);
    }
    return 0;
}