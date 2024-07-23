#include <cassert>
#include <vector>
#include <algorithm>
#include <map>

std::vector<int> frequencySort(std::vector<int> &nums) {
    std::map<int, int> m;
    for (int n : nums) {
        ++m[n];
    }

    std::sort(nums.begin(), nums.end(), [&m](int a, int b) {
        if (m[a] == m[b]) {
            return a > b;
        }
        return m[a] < m[b];
    });

    return nums;
}

int main() {
    {
        std::vector<int> nums{1, 1, 2, 2, 2, 3};
        std::vector<int> expected{3, 1, 1, 2, 2, 2};
        auto ret = frequencySort(nums);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{2, 3, 1, 3, 2};
        std::vector<int> expected{1, 3, 3, 2, 2};
        auto ret = frequencySort(nums);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{-1, 1, -6, 4, 5, -6, 1, 4, 1};
        std::vector<int> expected{5, -1, 4, 4, -6, -6, 1, 1, 1};
        auto ret = frequencySort(nums);
        assert(ret == expected);
    }
    return 0;
}