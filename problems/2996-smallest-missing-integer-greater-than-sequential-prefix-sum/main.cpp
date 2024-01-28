#include <cassert>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>

int missingInteger(const std::vector<int> &nums) {
    std::set<int> s(nums.begin(), nums.end());

    int max_sum = nums[0];
    int sum = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] == nums[i - 1] + 1) {
            sum += nums[i];
        } else {
            break;
        }

        max_sum = std::max(max_sum, sum);
    }

    for (int i = 0;; ++i) {
        if (s.find(max_sum + i) == s.end()) {
            return max_sum + i;
        }
    }

    return -1;
}

int main() {
    {
        std::vector<int> nums{1, 2, 3, 2, 5};
        int ret = missingInteger(nums);
        assert(ret == 6);
    }
    {
        std::vector<int> nums{3, 4, 5, 1, 12, 14, 13};
        int ret = missingInteger(nums);
        assert(ret == 15);
    }
    {
        std::vector<int> nums{29, 30, 31, 32, 33, 34, 35, 36, 37};
        int ret = missingInteger(nums);
        assert(ret == 297);
    }
    {
        std::vector<int> nums{4, 5, 6, 7, 8, 8, 9, 4, 3, 2, 7};
        int ret = missingInteger(nums);
        assert(ret == 30);
    }
    {
        std::vector<int> nums{37, 1, 2, 9, 5, 8, 5, 2, 9, 4};
        int ret = missingInteger(nums);
        assert(ret == 38);
    }
    {
        std::vector<int> nums{14, 9, 6, 7, 9, 10, 4, 9, 9, 4, 4};
        int ret = missingInteger(nums);
        assert(ret == 15);
    }
    return 0;
}
