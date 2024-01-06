#include <cassert>
#include <vector>

bool hasTrailingZeros(const std::vector<int> &nums) {
    int even = 0;
    for (int num : nums) {
        if (num % 2 == 0) {
            ++even;
            if (even == 2) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    {
        std::vector<int> nums{1, 2, 3, 4, 5};
        assert(hasTrailingZeros(nums));
    }
    {
        std::vector<int> nums{2, 4, 8, 16};
        assert(hasTrailingZeros(nums));
    }
    {
        std::vector<int> nums{1, 3, 5, 7, 9};
        assert(!hasTrailingZeros(nums));
    }
    return 0;
}
