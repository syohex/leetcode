#include <cassert>
#include <vector>
#include <algorithm>
#include <map>

int numSubarrayBoundedMax(const std::vector<int> &nums, int left, int right) {
    int ret = 0;
    int start = -1;
    int end = -1;
    int len = nums.size();
    for (int i = 0; i < len; ++i) {
        if (nums[i] < left) {
            ret += end - start;
        } else if (nums[i] > right) {
            start = end = i;
        } else {
            end = i;
            ret += end - start;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{2, 1, 4, 3};
        assert(numSubarrayBoundedMax(nums, 2, 3) == 3);
    }
    {
        std::vector<int> nums{73, 55, 36, 5, 55, 14, 9, 7, 72, 52};
        assert(numSubarrayBoundedMax(nums, 32, 69) == 22);
    }
    return 0;
}
