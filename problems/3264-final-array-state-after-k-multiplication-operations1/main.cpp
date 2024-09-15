#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> getFinalState(std::vector<int> &nums, int k, int multiplier) {
    int len = nums.size();
    for (int i = 0; i < k; ++i) {
        int min_i = 0;
        int min = nums[0];
        for (int j = 1; j < len; ++j) {
            if (nums[j] < min) {
                min = nums[j];
                min_i = j;
            }
        }

        nums[min_i] *= multiplier;
    }

    return nums;
}

int main() {
    {
        std::vector<int> nums{2, 1, 3, 5, 6};
        std::vector<int> expected{8, 4, 6, 5, 6};
        auto ret = getFinalState(nums, 5, 2);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{1, 2};
        std::vector<int> expected{16, 8};
        auto ret = getFinalState(nums, 3, 4);
        assert(ret == expected);
    }
    return 0;
}
