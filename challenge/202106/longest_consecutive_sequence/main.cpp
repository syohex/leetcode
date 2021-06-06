#include <cassert>
#include <vector>
#include <set>
#include <algorithm>

int longestConsecutive(const std::vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }

    std::set<int> s(nums.begin(), nums.end());

    int ret = 1;
    for (int n : nums) {
        int tmp = 1;
        while (s.find(n + 1) != s.end()) {
            ++tmp;
            ++n;
        }

        ret = std::max(ret, tmp);
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{100, 4, 200, 1, 3, 2};
        assert(longestConsecutive(nums) == 4);
    }
    {
        std::vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
        assert(longestConsecutive(nums) == 9);
    }
    return 0;
}