#include <cassert>
#include <vector>
#include <algorithm>
#include <climits>

int threeSumClosest(std::vector<int> &nums, int target) {
    int len = nums.size();
    std::sort(nums.begin(), nums.end());

    int min_diff = INT_MAX;
    int ret = 0;
    for (int i = 0; i < len - 2; ++i) {
        int left = i + 1;
        int right = len - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) {
                return target;
            }

            int diff = std::abs(target - sum);
            if (diff < min_diff) {
                min_diff = diff;
                ret = sum;
            }

            if (sum > target) {
                --right;
            } else {
                ++left;
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{-1, 2, 1, -4};
        assert(threeSumClosest(nums, 1) == 2);
    }
    return 0;
}
