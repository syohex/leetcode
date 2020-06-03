#include <cassert>
#include <vector>
#include <algorithm>

int removeElement(std::vector<int> &nums, int val) {
    int index = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] == val) {
            continue;
        }

        nums[index++] = nums[i];
    }

    return index;
}

bool equal(int size, const std::vector<int> &nums, const std::vector<int> &expected) {
    return std::equal(nums.begin(), nums.begin() + size, expected.begin());
}

int main(void) {
    {
        std::vector<int> nums{};
        int ret = removeElement(nums, 9);
        assert(equal(ret, nums, std::vector<int>{}));
    }
    {
        std::vector<int> nums{3, 2, 2, 3};
        int ret = removeElement(nums, 3);
        assert(equal(ret, nums, std::vector<int>{2, 2}));
    }
    {
        std::vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
        int ret = removeElement(nums, 2);
        assert(equal(ret, nums, std::vector<int>{0, 1, 3, 0, 4}));
    }
    return 0;
}