#include <cassert>
#include <vector>

std::vector<int> singleNumber(const std::vector<int> &nums) {
    long n = 0;
    for (int num : nums) {
        n ^= num;
    }

    int x = 0;
    long mask = n & -n;
    for (int num : nums) {
        if ((num & mask) != 0) {
            x ^= num;
        }
    }

    return {x, static_cast<int>(n ^ x)};
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