#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

int findNumberOfLIS(const std::vector<int> &nums) {
    int len = nums.size();
    std::vector<int> dp_length(len, 1);
    std::vector<int> dp_count(len, 1);
    int max_len = 1;

    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                if (dp_length[j] + 1 > dp_length[i]) {
                    dp_length[i] = dp_length[j] + 1;
                    dp_count[i] = 0;
                    max_len = std::max(max_len, dp_length[i]);
                }
                if (dp_length[j] + 1 == dp_length[i]) {
                    dp_count[i] += dp_count[j];
                }
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < len; ++i) {
        if (dp_length[i] == max_len) {
            ret += dp_count[i];
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 3, 5, 4, 7};
        int ret = findNumberOfLIS(nums);
        assert(ret == 2);
    }
    {
        std::vector<int> nums{2, 2, 2, 2, 2};
        int ret = findNumberOfLIS(nums);
        assert(ret == 5);
    }
    return 0;
}
