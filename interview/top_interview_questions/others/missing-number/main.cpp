#include <cassert>
#include <vector>

int missingNumber(const std::vector<int> &nums) {
    size_t val = nums.size();
    for (size_t i = 0; i < nums.size(); ++i) {
        val = val ^ i ^ nums[i];
    }

    return static_cast<int>(val);
}

int main() {
    {
        std::vector<int> nums{3, 0, 1};
        assert(missingNumber(nums) == 2);
    }
    {
        std::vector<int> nums{0, 1};
        assert(missingNumber(nums) == 2);
    }
    {
        std::vector<int> nums{9, 6, 4, 2, 3, 5, 7, 0, 1};
        assert(missingNumber(nums) == 8);
    }
    {
        std::vector<int> nums{0};
        assert(missingNumber(nums) == 1);
    }
    return 0;
}
