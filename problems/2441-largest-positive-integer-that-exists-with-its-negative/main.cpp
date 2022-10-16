#include <cassert>
#include <vector>
#include <set>
#include <algorithm>
#include <limits>

int findMaxK(const std::vector<int> &nums) {
    std::set<int> s(nums.begin(), nums.end());

    int ret = std::numeric_limits<int>::min();
    for (int i : s) {
        if (i < 0) {
            continue;
        }

        if (s.find(-i) != s.end()) {
            ret = std::max(ret, i);
        }
    }

    return ret == std::numeric_limits<int>::min() ? -1 : ret;
}

int main() {
    {
        std::vector<int> nums{-1, 2, -3, 3};
        int ret = findMaxK(nums);
        assert(ret == 3);
    }
    {
        std::vector<int> nums{-1, 10, 6, 7, -7, 1};
        int ret = findMaxK(nums);
        assert(ret == 7);
    }
    {
        std::vector<int> nums{-10, 8, 6, 7, -2, -3};
        int ret = findMaxK(nums);
        assert(ret == -1);
    }
    return 0;
}