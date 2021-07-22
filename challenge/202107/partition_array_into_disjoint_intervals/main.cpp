#include <cassert>
#include <vector>
#include <algorithm>
#include <climits>

int partitionDisjoint(const std::vector<int> &nums) {
    int len = nums.size();
    std::vector<int> maxs(len);
    std::vector<int> mins(len);

    int tmp = -1;
    for (int i = 0; i < len; ++i) {
        maxs[i] = std::max(tmp, nums[i]);
        tmp = maxs[i];
    }

    tmp = INT_MAX;
    for (int i = len - 1; i >= 0; --i) {
        mins[i] = std::min(tmp, nums[i]);
        tmp = mins[i];
    }

    for (int i = 1; i < len; ++i) {
        if (maxs[i - 1] <= mins[i]) {
            return i;
        }
    }

    // never reach here
    return -1;
}

int main() {
    {
        std::vector<int> nums{5, 0, 3, 8, 6};
        assert(partitionDisjoint(nums) == 3);
    }
    {
        std::vector<int> nums{1, 1, 1, 0, 6, 12};
        assert(partitionDisjoint(nums) == 4);
    }
    {
        std::vector<int> nums{1, 1};
        assert(partitionDisjoint(nums) == 1);
    }
    return 0;
}