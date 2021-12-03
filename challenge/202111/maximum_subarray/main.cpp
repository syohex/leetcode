#include <cassert>
#include <vector>
#include <algorithm>
#include <climits>

int maxSubArray(const std::vector<int> &nums) {
    int sum = 0;
    int ret = INT_MIN;
    for (int num : nums) {
        if (sum + num > num) {
            sum += num;
        } else {
            sum = num;
        }

        ret = std::max(ret, sum);
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
        assert(maxSubArray(nums) == 6);
    }
    {
        std::vector<int> nums{1};
        assert(maxSubArray(nums) == 1);
    }
    {
        std::vector<int> nums{5, 4, -1, 7, 8};
        assert(maxSubArray(nums) == 23);
    }
    return 0;
}