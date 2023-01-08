#include <cassert>
#include <vector>
#include <algorithm>

int maximumCount(const std::vector<int> &nums) {
    int positives = 0;
    int negatives = 0;

    for (int num : nums) {
        if (num > 0) {
            ++positives;
        } else if (num < 0) {
            ++negatives;
        }
    }

    return std::max(positives, negatives);
}

int main() {
    {
        std::vector<int> nums{-2, -1, -1, 1, 2, 3};
        int ret = maximumCount(nums);
        assert(ret == 3);
    }
    {
        std::vector<int> nums{-3, -2, -1, 0, 0, 1, 2};
        int ret = maximumCount(nums);
        assert(ret == 3);
    }
    {
        std::vector<int> nums{5, 20, 66, 1314};
        int ret = maximumCount(nums);
        assert(ret == 4);
    }
    return 0;
}
