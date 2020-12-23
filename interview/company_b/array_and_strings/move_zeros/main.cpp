#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

void moveZeros(std::vector<int> &nums) {
    int pos = 0;
    for (const auto num : nums) {
        if (num != 0) {
            nums[pos++] = num;
        }
    }

    int zeros = static_cast<int>(nums.size()) - pos;
    for (int i = 0; i < zeros; ++i) {
        nums[pos++] = 0;
    }
}

int main() {
    {
        std::vector<int> nums{0, 1, 0, 3, 12};
        moveZeros(nums);
        assert((nums == std::vector<int>{1, 3, 12, 0, 0}));
    }
    {
        std::vector<int> nums{};
        moveZeros(nums); // check sanitization errors
    }
    return 0;
}
