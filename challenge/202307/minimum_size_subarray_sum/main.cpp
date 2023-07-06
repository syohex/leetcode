#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>

int minSubArrayLen(int target, const std::vector<int> &nums) {
    int left = 0;
    int right = 0;
    int len = nums.size();
    int sum = 0;
    int ret = std::numeric_limits<int>::max();

    for (; right < len; ++right) {
        sum += nums[right];

        while (sum >= target) {
            ret = std::min(ret, right - left + 1);
            sum -= nums[left];
            ++left;
        }
    }

    if (ret == std::numeric_limits<int>::max()) {
        return 0;
    }

    return ret;
}

int main() {
    {
        int target = 7;
        std::vector<int> nums{2, 3, 1, 2, 4, 3};
        int ret = minSubArrayLen(target, nums);
        assert(ret == 2);
    }
    {
        int target = 4;
        std::vector<int> nums{1, 4, 4};
        int ret = minSubArrayLen(target, nums);
        assert(ret == 1);
    }
    {
        int target = 11;
        std::vector<int> nums{1, 1, 1, 1, 1, 1, 1, 1};
        int ret = minSubArrayLen(target, nums);
        assert(ret == 0);
    }
    return 0;
}
