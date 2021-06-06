#include <cassert>
#include <vector>
#include <set>
#include <algorithm>

int longestConsecutive(std::vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }

    std::sort(nums.begin(), nums.end());

    int ret = 1;
    int tmp = 1;
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] == nums[i - 1] + 1) {
            ++tmp;
        } else if (nums[i] == nums[i - 1]) {
        } else {
            ret = std::max(ret, tmp);
            tmp = 1;
        }
    }

    ret = std::max(ret, tmp);
    return ret;
}

int main() {
    {
        std::vector<int> nums{100, 4, 200, 1, 3, 2};
        assert(longestConsecutive(nums) == 4);
    }
    {
        std::vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
        assert(longestConsecutive(nums) == 9);
    }
    {
        std::vector<int> nums;
        assert(longestConsecutive(nums) == 0);
    }
    {
        std::vector<int> nums{9};
        assert(longestConsecutive(nums) == 1);
    }
    {
        std::vector<int> nums{1, 2, 0, 1};
        assert(longestConsecutive(nums) == 3);
    }
    return 0;
}