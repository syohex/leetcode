#include <cassert>
#include <vector>

int subArraysDivByK(const std::vector<int> &nums, int k) {
    int len = nums.size();
    std::vector<int> acc(len + 1, 0);
    for (int i = 0; i < len; ++i) {
        acc[i + 1] = nums[i] + acc[i];
    }

    int ret = 0;
    for (int i = 1; i <= len; ++i) {
        for (int j = 0; j < i; ++j) {
            if ((acc[i] - acc[j]) % k == 0) {
                ++ret;
            }
        }
    }
    return ret;
}

int main() {
    {
        std::vector<int> nums{4, 5, 0, -2, -3, 1};
        int ret = subArraysDivByK(nums, 5);
        assert(ret == 7);
    }
    {
        std::vector<int> nums{5};
        int ret = subArraysDivByK(nums, 9);
        assert(ret == 0);
    }
    return 0;
}
