#include <cassert>
#include <vector>

void moveZeros(std::vector<int> &nums) {
    size_t nonZero = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0) {
            continue;
        }

        nums[nonZero++] = nums[i];
    }

    for (size_t i = nonZero; i < nums.size(); ++i) {
        nums[i] = 0;
    }
}

int main() {
    std::vector<int> nums;
    nums = std::vector<int>{0, 1, 0, 3, 12};
    moveZeros(nums);
    assert((nums == std::vector<int>{1, 3, 12, 0, 0}));
    return 0;
}
