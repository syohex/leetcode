#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>

int maxSubarraySumCircular(const std::vector<int> &nums) {
    int sum = 0;
    int max_sum = std::numeric_limits<int>::min();
    int min_sum = std::numeric_limits<int>::max();
    int current_min = 0;
    int current_max = 0;
    for (int num : nums) {
        current_max = std::max(current_max + num, num);
        max_sum = std::max(max_sum, current_max);

        current_min = std::min(current_min + num, num);
        min_sum = std::min(min_sum, current_min);

        sum += num;
    }

    if (max_sum > 0) {
        return std::max(max_sum, sum - min_sum);
    } else {
        return max_sum;
    }
}

int main() {
    {
        std::vector<int> nums{1, -2, 3, -2};
        int ret = maxSubarraySumCircular(nums);
        assert(ret == 3);
    }
    {
        std::vector<int> nums{5, -3, 5};
        int ret = maxSubarraySumCircular(nums);
        assert(ret == 10);
    }
    {
        std::vector<int> nums{-3, -2, -3};
        int ret = maxSubarraySumCircular(nums);
        assert(ret == -2);
    }
    return 0;
}
