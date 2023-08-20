#include <cassert>
#include <vector>

int countPairs(const std::vector<int> &nums, int target) {
    int ret = 0;
    int len = nums.size();
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (nums[i] + nums[j] < target) {
                ++ret;
            }
        }
    }
    return ret;
}

int main() {
    {
        std::vector<int> nums{-1, 1, 2, 3, 1};
        int ret = countPairs(nums, 2);
        assert(ret == 3);
    }
    {
        std::vector<int> nums{-6, 2, 5, -2, -7, -1, 3};
        int ret = countPairs(nums, -2);
        assert(ret == 10);
    }
    return 0;
}
