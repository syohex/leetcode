#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>

bool canBeIncreasing(const std::vector<int> &nums) {
    const auto f = [&nums](size_t pos) -> bool {
        size_t prev = pos == 0 ? 1 : 0;
        size_t start = pos == 0 ? 2 : 1;
        for (size_t i = start; i < nums.size(); ++i) {
            if (i == pos) {
                continue;
            }

            if (nums[i] <= nums[prev]) {
                return false;
            }

            prev = i;
        };

        return true;
    };

    for (size_t i = 0; i < nums.size(); ++i) {
        if (f(i)) {
            return true;
        }
    }

    return false;
}

int main() {
    {
        std::vector<int> nums{1, 2, 10, 5, 7};
        assert(canBeIncreasing(nums));
    }
    {
        std::vector<int> nums{2, 3, 1, 2};
        assert(!canBeIncreasing(nums));
    }
    {
        std::vector<int> nums{1, 1, 1};
        assert(!canBeIncreasing(nums));
    }
    {
        std::vector<int> nums{1, 2, 3};
        assert(canBeIncreasing(nums));
    }
    return 0;
}
