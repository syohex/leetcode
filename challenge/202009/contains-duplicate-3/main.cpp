#include <cassert>
#include <vector>
#include <cmath>
#include <cstdio>

bool containsNearByAlmostDuplicate(const std::vector<int> &nums, int k, int t) {
    if (nums.empty()) {
        return false;
    }

    for (size_t i = 0; i < nums.size() - 1; ++i) {
        size_t limit;
        if (i + k < nums.size()) {
            limit = i + k + 1;
        } else {
            limit = nums.size();
        }
        for (size_t j = i + 1; j < limit; ++j) {
            if (std::abs(static_cast<long long>(nums[i]) - static_cast<long long>(nums[j])) <= t) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    {
        std::vector<int> input{};
        assert(!containsNearByAlmostDuplicate(input, 3, 0));
    }
    {
        std::vector<int> input{1, 2, 3, 1};
        assert(containsNearByAlmostDuplicate(input, 3, 0));
    }
    {
        std::vector<int> input{1, 0, 1, 1};
        assert(containsNearByAlmostDuplicate(input, 3, 0));
    }
    {
        std::vector<int> input{1, 5, 9, 1, 5, 9};
        assert(!containsNearByAlmostDuplicate(input, 2, 3));
    }
    return 0;
}
