#include <cassert>
#include <vector>
#include <cmath>

std::vector<int> getMaximumXor(const std::vector<int> &nums, int maximumBit) {
    std::vector<int> xors(nums.size());
    int len = nums.size();
    int tmp = 0;
    for (int i = 0; i < len; ++i) {
        tmp ^= nums[i];
        xors[len - i - 1] = tmp;
    }

    unsigned int mask = std::pow(2, maximumBit) - 1;
    std::vector<int> ret;
    for (int x : xors) {
        ret.push_back(~x & mask);
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{0, 1, 1, 3};
        std::vector<int> expected{0, 3, 2, 3};

        auto ret = getMaximumXor(nums, 2);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{2, 3, 4, 7};
        std::vector<int> expected{5, 2, 6, 5};

        auto ret = getMaximumXor(nums, 3);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{0, 1, 2, 2, 5, 7};
        std::vector<int> expected{4, 3, 6, 4, 6, 7};

        auto ret = getMaximumXor(nums, 3);
        assert(ret == expected);
    }
}