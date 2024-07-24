#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

std::vector<int> sortJumbled(const std::vector<int> &mapping, const std::vector<int> &nums) {
    const auto convert = [&](int n) {
        if (n == 0) {
            return mapping[0];
        }

        int ret = 0;
        int v = 1;
        while (n > 0) {
            ret = ret + v * mapping[n % 10];
            n /= 10;
            v *= 10;
        }
        return ret;
    };

    struct Data {
        int orig;
        int mapped;
        std::size_t index;
    };

    std::vector<Data> v;
    for (std::size_t i = 0; i < nums.size(); ++i) {
        v.push_back({nums[i], convert(nums[i]), i});
    }

    std::sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
        if (a.mapped == b.mapped) {
            return a.index < b.index;
        }

        return a.mapped < b.mapped;
    });

    std::vector<int> ret;
    for (const auto &a : v) {
        ret.push_back(a.orig);
    }

    return ret;
}

int main() {
    {
        std::vector<int> mapping{8, 9, 4, 0, 2, 1, 3, 5, 7, 6};
        std::vector<int> nums{991, 338, 38};
        std::vector<int> expected{338, 38, 991};
        auto ret = sortJumbled(mapping, nums);
        assert(ret == expected);
    }
    {
        std::vector<int> mapping{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::vector<int> nums{789, 456, 123};
        std::vector<int> expected{123, 456, 789};
        auto ret = sortJumbled(mapping, nums);
        assert(ret == expected);
    }
    {
        std::vector<int> mapping{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
        std::vector<int> nums{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::vector<int> expected{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
        auto ret = sortJumbled(mapping, nums);
        assert(ret == expected);
    }
    return 0;
}