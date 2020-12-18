#include <cassert>
#include <vector>
#include <algorithm>

bool increasingTriplet(const std::vector<int> &nums) {
    if (nums.size() < 3) {
        return false;
    }

    int first = INT_MAX;
    int second = INT_MAX;

    for (const int num : nums) {
        if (num <= first) {
            first = num;
        } else if (num <= second) {
            second = num;
        } else {
            return true;
        }
    }

    return false;
}

int main() {
    {
        std::vector<int> nums{1, 2, 3, 4, 5};
        assert(increasingTriplet(nums));
    }
    {
        std::vector<int> nums{5, 4, 3, 2, 1};
        assert(!increasingTriplet(nums));
    }
    {
        std::vector<int> nums{2, 1, 5, 9, 0, 4, 6};
        assert(increasingTriplet(nums));
    }
    {
        std::vector<int> nums{1, 2, 3, 1, 2, 1};
        assert(increasingTriplet(nums));
    }
    return 0;
}
