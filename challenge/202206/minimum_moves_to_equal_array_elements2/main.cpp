#include <cassert>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <map>
#include <set>
#include <limits>
#include <cmath>

int minMove2(const std::vector<int> &nums) {
    std::int64_t ret = std::numeric_limits<std::int64_t>::max();
    for (int i : nums) {
        std::int64_t sum = 0;
        for (int j : nums) {
            sum += std::abs(i - j);
        }

        ret = std::min(ret, sum);
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 2, 3};
        int ret = minMove2(nums);
        assert(ret == 2);
    }
    {
        std::vector<int> nums{1, 10, 2, 9};
        int ret = minMove2(nums);
        assert(ret == 16);
    }
    {
        std::vector<int> nums{1, 0, 0, 8, 6};
        int ret = minMove2(nums);
        assert(ret == 14);
    }
    return 0;
}
