#include <cassert>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <cstdio>

int lengthOfLIS(const std::vector<int> &nums) {
    std::map<std::pair<size_t, int>, int> cache;
    std::function<int(size_t pos, int prev)> f;
    f = [&](size_t pos, int prev) -> int {
        if (pos >= nums.size()) {
            return 0;
        }

        if (cache.find({pos, prev}) != cache.end()) {
            return cache[{pos, prev}];
        }

        int ret = 0;
        for (size_t i = pos; i < nums.size(); ++i) {
            if (nums[i] > prev) {
                ret = std::max(ret, f(i + 1, nums[i]) + 1);
            }
            ret = std::max(ret, f(i + 1, prev));
        }

        cache[{pos, prev}] = ret;
        return ret;
    };

    return f(0, -1000000);
}

int main() {
    {
        std::vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
        int ret = lengthOfLIS(nums);
        assert(ret == 4);
    }
    {
        std::vector<int> nums{0, 1, 0, 3, 2, 3};
        int ret = lengthOfLIS(nums);
        assert(ret == 4);
    }
    {
        std::vector<int> nums{7, 7, 7, 7, 7, 7, 7};
        int ret = lengthOfLIS(nums);
        assert(ret == 1);
    }
    {
        std::vector<int> nums{3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12};
        int ret = lengthOfLIS(nums);
        assert(ret == 6);
    }
    return 0;
}
