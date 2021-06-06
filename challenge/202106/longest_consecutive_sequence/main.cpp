#include <cassert>
#include <vector>
#include <set>
#include <algorithm>

int longestConsecutive(const std::vector<int> &nums) {
    std::set<int> s(nums.begin(), nums.end());
    std::set<int> checked;

    int ret = 0;
    for (int n : nums) {
        if (checked.find(n) != checked.end()) {
            continue;
        }

        checked.insert(n);

        int tmp = 1;
        while (s.find(n + 1) != s.end()) {
            checked.insert(n + 1);
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
    {
        std::vector<int> nums;
        assert(longestConsecutive(nums) == 0);
    }
    return 0;
}