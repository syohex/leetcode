#include <cassert>
#include <vector>

int smallestEqual(const std::vector<int> &nums) {
    for (size_t i = 0; i < nums.size(); ++i) {
        if (i % 10 == nums[i]) {
            return i;
        }
    }

    return -1;
}

int main() {
    {
        std::vector<int> nums{0, 1, 2};
        assert(smallestEqual(nums) == 0);
    }
    {
        std::vector<int> nums{4, 3, 2, 1};
        assert(smallestEqual(nums) == 2);
    }
    {
        std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        assert(smallestEqual(nums) == -1);
    }
    {
        std::vector<int> nums{2, 1, 3, 5, 2};
        assert(smallestEqual(nums) == 1);
    }
    return 0;
}