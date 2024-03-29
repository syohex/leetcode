#include <cassert>
#include <algorithm>

long long countSubarrays(const std::vector<int> &nums, int k) {
    int max_val = 0;
    for (int num : nums) {
        max_val = std::max(max_val, num);
    }

    int len = nums.size();
    std::vector<int> acc(len + 1, 0);
    for (int i = 0; i < len; ++i) {
        if (nums[i] == max_val) {
            acc[i + 1] = acc[i] + 1;
        } else {
            acc[i + 1] = acc[i];
        }
    }

    long long ret = 0;
    for (int i = 1; i <= len; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (acc[i] - acc[j] >= k) {
                ++ret;
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 3, 2, 3, 3};
        auto ret = countSubarrays(nums, 2);
        assert(ret == 6);
    }
    {
        std::vector<int> nums{1, 4, 2, 1};
        auto ret = countSubarrays(nums, 3);
        assert(ret == 0);
    }
    return 0;
}
