#include <cassert>
#include <vector>

int minStartValue(const std::vector<int> &nums) {
    int sum = nums[0];
    int min = sum;
    for (size_t i = 1; i < nums.size(); ++i) {
        sum += nums[i];
        if (sum < min) {
            min = sum;
        }
    }

    if (min >= 1) {
        return 1;
    }

    return 1 - min;
}

int main() {
    {
        std::vector<int> nums{-3, 2, -3, 4, 2};
        assert(minStartValue(nums) == 5);
    }
    {
        std::vector<int> nums{1, 2};
        assert(minStartValue(nums) == 1);
    }
    {
        std::vector<int> nums{1, -2, -3};
        assert(minStartValue(nums) == 5);
    }
    return 0;
}
