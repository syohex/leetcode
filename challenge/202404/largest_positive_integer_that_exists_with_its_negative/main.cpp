#include <cassert>
#include <vector>
#include <algorithm>
#include <set>

int findMaxK(const std::vector<int> &nums) {
    std::set<int> s(nums.begin(), nums.end());

    int ret = -1;
    for (int num : nums) {
        if (num > 0 && s.find(-num) != s.end()) {
            ret = std::max(ret, num);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{-1, 2, -3, 3};
        int ret = findMaxK(nums);
        assert(ret == 3);
    }
    {
        std::vector<int> nums{-1, 10, 6, 7, -7, 1};
        int ret = findMaxK(nums);
        assert(ret == 7);
    }
    {
        std::vector<int> nums{-10, 8, 6, 7, -2, -3};
        int ret = findMaxK(nums);
        assert(ret == -1);
    }
    return 0;
}
