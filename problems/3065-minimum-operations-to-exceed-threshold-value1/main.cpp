#include <cassert>
#include <vector>
#include <algorithm>

int minOperations(std::vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());
    auto p = std::lower_bound(nums.begin(), nums.end(), k);
    return p - nums.begin();
}

int main() {
    {
        std::vector<int> nums{2, 11, 10, 1, 3};
        int ret = minOperations(nums, 10);
        assert(ret == 3);
    }
    {
        std::vector<int> nums{1, 1, 2, 4, 9};
        int ret = minOperations(nums, 1);
        assert(ret == 0);
    }
    {
        std::vector<int> nums{1, 1, 2, 4, 9};
        int ret = minOperations(nums, 9);
        assert(ret == 4);
    }
    return 0;
}
