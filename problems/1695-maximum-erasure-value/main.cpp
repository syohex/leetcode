#include <cassert>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>

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
        std::vector<int> input{4, 2, 4, 5, 6};
        assert(maximumUniqueSubarray(input) == 17);
    }
    {
        std::vector<int> input{5, 2, 1, 2, 5, 2, 1, 2, 5};
        assert(maximumUniqueSubarray(input) == 8);
    }
    {
        std::vector<int> input{1, 1, 1, 1, 1, 1, 1, 1, 1};
        assert(maximumUniqueSubarray(input) == 1);
    }
    {
        std::vector<int> input{10000};
        assert(maximumUniqueSubarray(input) == 10000);
    }
    {
        std::vector<int> input{558, 508, 782, 32, 187, 103, 370, 607, 619, 267, 984, 10};
        assert(maximumUniqueSubarray(input) == 5027);
    }
    return 0;
}
