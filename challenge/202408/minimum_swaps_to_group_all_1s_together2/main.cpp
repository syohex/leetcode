#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

int minSwaps(const std::vector<int> &nums) {
    const auto f = [&](int val) -> int {
        int total = 0;
        for (int num : nums) {
            if (num == val) {
                ++total;
            }
        }

        int len = nums.size();
        if (total == len || total == 0) {
            return 0;
        }

        int val_in_window = 0;
        int left = 0;
        int right = 0;
        while (right < total) {
            if (nums[right] == val) {
                ++val_in_window;
            }
            ++right;
        }

        int max_count = val_in_window;
        while (right < len) {
            if (nums[left] == val) {
                --val_in_window;
            }
            if (nums[right] == val) {
                ++val_in_window;
            }

            max_count = std::max(max_count, val_in_window);

            ++left;
            ++right;
        }

        return total - max_count;
    };

    return std::min(f(0), f(1));
}

int main() {
    {
        std::vector<int> nums{0, 1, 0, 1, 1, 0, 0};
        int ret = minSwaps(nums);
        assert(ret == 1);
    }
    {
        std::vector<int> nums{0, 1, 1, 1, 0, 0, 1, 1, 0};
        int ret = minSwaps(nums);
        assert(ret == 2);
    }
    {
        std::vector<int> nums{1, 1, 0, 0, 1};
        int ret = minSwaps(nums);
        assert(ret == 0);
    }
    return 0;
}