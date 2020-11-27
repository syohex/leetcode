#include <cassert>
#include <vector>
#include <algorithm>

int removeDuplicates(std::vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }

    int prev = nums[0];
    int ret = 1;
    for (size_t i = 1; i < nums.size(); ++i) {
        if (prev != nums[i]) {
            nums[ret] = nums[i];
            prev = nums[i];
            ++ret;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 1, 2};
        std::vector<int> expected{1, 2};
        int n = removeDuplicates(nums);
        assert(std::equal(nums.begin(), nums.begin() + n, expected.begin(), expected.end()));
    }
    {
        std::vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        std::vector<int> expected{0, 1, 2, 3, 4};
        int n = removeDuplicates(nums);
        assert(std::equal(nums.begin(), nums.begin() + n, expected.begin(), expected.end()));
    }

    return 0;
}
