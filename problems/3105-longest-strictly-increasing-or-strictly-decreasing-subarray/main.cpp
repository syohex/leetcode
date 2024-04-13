#include <cassert>
#include <vector>
#include <algorithm>

int longestMonotonicSubarray(const std::vector<int> &nums) {
    int ret = 1;
    int len = nums.size();

    for (int i = 0; i < len - 1; ++i) {
        if (nums[i] == nums[i + 1]) {
            continue;
        }

        bool up = nums[i] < nums[i + 1];
        int s = 2;
        for (int j = i + 2; j < len; ++j) {
            if (up && nums[j - 1] < nums[j]) {
                ++s;
            } else if (!up && nums[j - 1] > nums[j]) {
                ++s;
            } else {
                break;
            }
        }

        ret = std::max(ret, s);
    }
    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 4, 3, 3, 2};
        int ret = longestMonotonicSubarray(nums);
        assert(ret == 2);
    }
    {
        std::vector<int> nums{3, 3, 3, 3};
        int ret = longestMonotonicSubarray(nums);
        assert(ret == 1);
    }
    {
        std::vector<int> nums{3, 2, 1};
        int ret = longestMonotonicSubarray(nums);
        assert(ret == 3);
    }
    return 0;
}
