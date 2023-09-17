#include <cassert>
#include <vector>
#include <cstddef>
#include <bit>

int sumIndicesWithKSetBits(const std::vector<int> &nums, int k) {
    int ret = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (std::popcount(i) == k) {
            ret += nums[i];
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{5, 10, 1, 5, 2};
        int ret = sumIndicesWithKSetBits(nums, 1);
        assert(ret == 13);
    }
    {
        std::vector<int> nums{4, 3, 2, 1};
        int ret = sumIndicesWithKSetBits(nums, 2);
        assert(ret == 1);
    }
    return 0;
}
