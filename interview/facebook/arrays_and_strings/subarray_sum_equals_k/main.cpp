#include <cassert>
#include <vector>

int subarraySum(const std::vector<int> &nums, int k) {
    std::vector<int> sums(nums.size() + 1);
    sums[0] = 0;
    for (size_t i = 1; i <= nums.size(); ++i) {
        sums[i] = nums[i - 1] + sums[i - 1];
    }

    int ret = 0;
    for (size_t i = 1; i <= nums.size(); ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (sums[i] - sums[j] == k) {
                ++ret;
            }
        }
    }
    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 1, 1};
        assert(subarraySum(nums, 2) == 2);
    }
    {
        std::vector<int> nums{1, 2, 3};
        assert(subarraySum(nums, 3) == 2);
    }
    return 0;
}
