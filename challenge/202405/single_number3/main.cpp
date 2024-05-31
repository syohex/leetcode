#include <cassert>
#include <vector>
#include <cstdio>

std::vector<int> singleNumber(const std::vector<int> &nums) {
    long v = 0;
    for (int num : nums) {
        v ^= num;
    }

    long mask = v & -v;
    long x = 0;
    for (int num : nums) {
        if ((num & mask) != 0) {
            x ^= num;
        }
    }

    return {static_cast<int>(x), static_cast<int>(v ^ x)};
}

int main() {
    {
        std::vector<int> nums{1, 2, 1, 3, 2, 5};
        std::vector<int> expected{3, 5};
        auto ret = singleNumber(nums);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{-1, 0};
        std::vector<int> expected{-1, 0};
        auto ret = singleNumber(nums);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{0, 1};
        std::vector<int> expected{1, 0};
        auto ret = singleNumber(nums);
        assert(ret == expected);
    }
    return 0;
}
