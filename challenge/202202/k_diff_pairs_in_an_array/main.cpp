#include <cassert>
#include <vector>
#include <algorithm>

int findPairs(std::vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());

    int len = nums.size();
    int left = 0;
    int right = 0;
    int ret = 0;

    while (left < len && right < len) {
        int diff = nums[right] - nums[left];
        if (left == right || diff < k) {
            ++right;
        } else if (diff > k) {
            ++left;
        } else {
            ++left;
            ++ret;

            while (left < len && nums[left - 1] == nums[left]) {
                ++left;
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{3, 1, 4, 1, 5};
        assert(findPairs(nums, 2) == 2);
    }
    {
        std::vector<int> nums{1, 2, 3, 4, 5};
        assert(findPairs(nums, 1) == 4);
    }
    {
        std::vector<int> nums{1, 3, 1, 5, 4};
        assert(findPairs(nums, 0) == 1);
    }
    return 0;
}