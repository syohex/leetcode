#include <cassert>
#include <vector>
#include <algorithm>

int longestAlternatingSubarray(const std::vector<int> &nums, int threshold) {
    int ret = 0;
    int len = nums.size();

    for (int i = 0; i < len; ++i) {
        if (nums[i] % 2 != 0 || nums[i] > threshold) {
            continue;
        }

        int count = 1;
        int bit = 1;
        for (int j = i + 1; j < len; ++j) {
            if (nums[j] % 2 != bit || nums[j] > threshold) {
                break;
            }

            ++count;
            bit = bit == 1 ? 0 : 1;
        }

        ret = std::max(ret, count);
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{3, 2, 5, 4};
        int threshold = 5;
        int ret = longestAlternatingSubarray(nums, threshold);
        assert(ret == 3);
    }
    {
        std::vector<int> nums{1, 2};
        int threshold = 2;
        int ret = longestAlternatingSubarray(nums, threshold);
        assert(ret == 1);
    }
    {
        std::vector<int> nums{2, 3, 4, 5};
        int threshold = 4;
        int ret = longestAlternatingSubarray(nums, threshold);
        assert(ret == 3);
    }
    {
        std::vector<int> nums{0};
        int threshold = 100;
        int ret = longestAlternatingSubarray(nums, threshold);
        assert(ret == 1);
    }
    {
        std::vector<int> nums{1};
        int threshold = 100;
        int ret = longestAlternatingSubarray(nums, threshold);
        assert(ret == 0);
    }
    {
        std::vector<int> nums{4};
        int threshold = 1;
        int ret = longestAlternatingSubarray(nums, threshold);
        assert(ret == 0);
    }
    return 0;
}
