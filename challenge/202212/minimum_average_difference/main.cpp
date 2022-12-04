#include <cassert>
#include <vector>
#include <cmath>
#include <limits>
#include <cstdio>
#include <cstdint>

int minimumAverageDifference(const std::vector<int> &nums) {
    int len = nums.size();
    std::vector<int64_t> acc;
    int64_t sum = 0;
    for (int num : nums) {
        sum += num;
        acc.push_back(sum);
    }

    int64_t min = std::numeric_limits<int64_t>::max();
    int64_t ret = -1;
    for (int i = 0; i < len; ++i) {
        int64_t a = acc[i] / (i + 1);
        int64_t b;
        if (i + 1 == len) {
            b = 0;
        } else {
            b = (sum - acc[i]) / (len - (i + 1));
        }

        int64_t diff = std::abs(a - b);
        if (diff < min) {
            ret = i;
            min = diff;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{2, 5, 3, 9, 5, 3};
        int ret = minimumAverageDifference(nums);
        assert(ret == 3);
    }
    {
        std::vector<int> nums{0};
        int ret = minimumAverageDifference(nums);
        assert(ret == 0);
    }
    return 0;
}
