#include <cassert>
#include <vector>
#include <algorithm>

bool isGood(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    std::vector<int> v;
    for (int i = 1; i <= nums.back(); ++i) {
        v.push_back(i);
    }
    v.push_back(nums.back());

    return nums == v;
}

int main() {
    {
        std::vector<int> nums{2, 1, 3};
        assert(!isGood(nums));
    }
    {
        std::vector<int> nums{1, 3, 3, 2};
        assert(isGood(nums));
    }
    {
        std::vector<int> nums{1, 1};
        assert(isGood(nums));
    }
    {
        std::vector<int> nums{3, 4, 4, 1, 2, 1};
        assert(!isGood(nums));
    }

    return 0;
}
