#include <cassert>
#include <vector>

void moveZeros(std::vector<int> &nums) {
    size_t pos = 0;
    for (int n : nums) {
        if (n != 0) {
            nums[pos++] = n;
        }
    }

    for (size_t i = pos; i < nums.size(); ++i) {
        nums[i] = 0;
    }
}

int main() {
    {
        std::vector<int> nums{0, 1, 0, 3, 12};
        moveZeros(nums);
        assert((nums == std::vector<int>{1, 3, 12, 0, 0}));
    }
    {
        std::vector<int> nums{1, 2, 3, 4, 5};
        moveZeros(nums);
        assert((nums == std::vector<int>{1, 2, 3, 4, 5}));
    }
    return 0;
}
