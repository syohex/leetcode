#include <cassert>
#include <vector>
#include <set>
#include <cstdio>

std::vector<std::vector<int>> findMatrix(const std::vector<int> &nums) {
    std::vector<std::vector<int>> ret;
    int len = nums.size();
    int n = 0;

    std::vector<bool> checked(len, false);
    while (n < len) {
        std::set<int> s;

        for (int i = 0; i < len; ++i) {
            if (!checked[i] && s.find(nums[i]) == s.end()) {
                checked[i] = true;
                s.insert(nums[i]);
                ++n;
            }
        }

        ret.push_back({s.begin(), s.end()});
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 3, 4, 1, 2, 3, 1};
        std::vector<std::vector<int>> expected{
            {1, 2, 3, 4},
            {1, 3},
            {1},
        };
        auto ret = findMatrix(nums);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{1, 2, 3, 4};
        std::vector<std::vector<int>> expected{
            {1, 2, 3, 4},
        };
        auto ret = findMatrix(nums);
        assert(ret == expected);
    }
    return 0;
}
