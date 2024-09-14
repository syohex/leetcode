#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

int longestSubarray(const std::vector<int> &nums) {
    int ret = 0;
    int max = 0;
    int len = 0;

    for (int num : nums) {
        if (num > max) {
            max = num;
            ret = 0;
            len = 0;
        }

        if (num == max) {
            len += 1;
        } else {
            len = 0;
        }

        ret = std::max(ret, len);
    }
    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 2, 3, 3, 2, 2};
        int ret = longestSubarray(nums);
        assert(ret == 2);
    }
    {
        std::vector<int> nums{1, 2, 3, 4};
        int ret = longestSubarray(nums);
        assert(ret == 1);
    }
    return 0;
}
