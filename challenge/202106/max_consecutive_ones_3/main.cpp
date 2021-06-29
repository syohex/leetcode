#include <cassert>
#include <vector>
#include <algorithm>

int longestOnes(const std::vector<int> &nums, int k) {
    int start = 0, end = 0;
    int len = nums.size();

    int ret = 0;
    for (; end < len; ++end) {
        if (nums[end] == 0) {
            --k;
        }

        if (k < 0) {
            if (nums[start] == 0) {
                ++k;
            }

            ++start;
        }

        if (k >= 0) {
            ret = std::max(ret, end - start + 1);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
        assert(longestOnes(nums, 2) == 6);
    }
    {
        std::vector<int> nums{0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
        assert(longestOnes(nums, 3) == 10);
    }
    return 0;
}