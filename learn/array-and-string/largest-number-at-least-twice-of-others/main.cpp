#include <cassert>
#include <vector>
#include <algorithm>

int dominantIndex(const std::vector<int> &nums) {
    if (nums.size() <= 1) {
        return 0;
    }

    int max, max_index;
    int second_max, second_max_index;
    if (nums[0] > nums[1]) {
        max = nums[0];
        max_index = 0;
        second_max = nums[1];
        second_max_index = 1;
    } else {
        max = nums[1];
        max_index = 1;
        second_max = nums[0];
        second_max_index = 0;
    }

    for (size_t i = 2; i < nums.size(); ++i) {
        if (nums[i] > max) {
            second_max = max;
            second_max_index = max_index;
            max = nums[i];
            max_index = i;
        } else if (nums[i] > second_max && nums[i] != max) {
            second_max = nums[i];
            second_max_index = i;
        }
    }

    return (max >= 2 * second_max) ? max_index : -1;
}

int main() {
    {
        std::vector<int> nums{3, 6, 1, 0};
        assert(dominantIndex(nums) == 1);
    }
    {
        std::vector<int> nums{1, 2, 3, 4};
        assert(dominantIndex(nums) == -1);
    }
    {
        std::vector<int> nums{99};
        assert(dominantIndex(nums) == 0);
    }
    return 0;
}
