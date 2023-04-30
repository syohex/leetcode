#include <cassert>
#include <vector>
#include <algorithm>

int maximizeSum(const std::vector<int> &nums, int k) {
    int max = *std::max_element(nums.begin(), nums.end());
    return k * (max + max + k - 1) / 2;
}

int main() {
    {
        std::vector<int> nums{1, 2, 3, 4, 5};
        int ret = maximizeSum(nums, 3);
        assert(ret == 18);
    }
    {
        std::vector<int> nums{5, 5, 5};
        int ret = maximizeSum(nums, 2);
        assert(ret == 11);
    }
    {
        std::vector<int> nums{5, 5, 5};
        int ret = maximizeSum(nums, 1);
        assert(ret == 5);
    }
    return 0;
}
