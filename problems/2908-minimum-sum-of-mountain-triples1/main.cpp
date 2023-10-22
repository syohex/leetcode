#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>

int minimumSum(const std::vector<int> &nums) {
    int len = nums.size();
    bool found = false;
    int ret = std::numeric_limits<int>::max();

    for (int i = 0; i < len - 2; ++i) {
        for (int j = i + 1; j < len - 1; ++j) {
            for (int k = j + 1; k < len; ++k) {
                if (nums[i] < nums[j] && nums[k] < nums[j]) {
                    ret = std::min(ret, nums[i] + nums[j] + nums[k]);
                    found = true;
                }
            }
        }
    }

    if (!found) {
        return -1;
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{8, 6, 1, 5, 3};
        int ret = minimumSum(nums);
        assert(ret == 9);
    }
    {
        std::vector<int> nums{5, 4, 8, 7, 10, 2};
        int ret = minimumSum(nums);
        assert(ret == 13);
    }
    {
        std::vector<int> nums{6, 5, 4, 3, 4, 5};
        int ret = minimumSum(nums);
        assert(ret == -1);
    }
    return 0;
}
