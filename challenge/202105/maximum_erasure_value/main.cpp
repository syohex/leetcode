#include <cassert>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

int maximumUniqueSubarray(const std::vector<int> &nums) {
    std::vector<int> accs(nums.size() + 1);
    accs[0] = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        accs[i + 1] = nums[i] + accs[i];
    }

    std::map<size_t, size_t> m;
    size_t min_pos = 0;
    std::vector<size_t> unique_start(nums.size() + 1);
    for (size_t i = 0; i < nums.size(); ++i) {
        if (m.find(nums[i]) != m.end()) {
            min_pos = std::max(min_pos, m[nums[i]] + 1);
        }

        unique_start[i] = min_pos;
        m[nums[i]] = i;
    }

    int ret = 0;
    for (size_t i = 1; i <= nums.size(); ++i) {
        int val = accs[i] - accs[unique_start[i - 1]];
        ret = std::max(ret, val);
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{4, 2, 4, 5, 6};
        assert(maximumUniqueSubarray(nums) == 17);
    }
    {
        std::vector<int> nums{5, 2, 1, 2, 5, 2, 1, 2, 5};
        assert(maximumUniqueSubarray(nums) == 8);
    }
    {
        std::vector<int> nums{10000, 1, 10000, 1, 1, 1, 1, 1, 1};
        assert(maximumUniqueSubarray(nums) == 10001);
    }
    return 0;
}
