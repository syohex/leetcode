#include <cassert>
#include <vector>
#include <algorithm>

int maxProduct(const std::vector<int> &nums) {
    int max_val = nums[0];
    int min_val = nums[0];

    int ret = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        int tmp = std::max({nums[i], nums[i] * max_val, nums[i] * min_val});
        min_val = std::min({nums[i], nums[i] * max_val, nums[i] * min_val});
        max_val = tmp;

        ret = std::max(ret, max_val);
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{2, 3, -2, 4};
        assert(maxProduct(nums) == 6);
    }
    {
        std::vector<int> nums{-2, 0, -1};
        assert(maxProduct(nums) == 0);
    }
    return 0;
}
