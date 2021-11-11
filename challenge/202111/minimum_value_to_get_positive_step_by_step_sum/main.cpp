#include <cassert>
#include <vector>
#include <algorithm>
#include <climits>

int minStartValue(const std::vector<int> &nums) {
    int sum = 0;
    int min = INT_MAX;
    for (int num : nums) {
        sum += num;
        min = std::min(min, sum);
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