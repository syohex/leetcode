#include <cassert>
#include <vector>
#include <map>
#include <set>

std::vector<std::vector<int>> findMatrix(const std::vector<int> &nums) {
    std::vector<std::vector<int>> ret;
    int len = nums.size();
    std::vector<bool> checked(len, false);

    int n = 0;

    while (n < len) {
        std::set<int> s;

        for (int i = 0; i < len; ++i) {
            if (!checked[i] && s.find(nums[i]) == s.end()) {
                checked[i] = true;
                s.insert(nums[i]);
                ++n;
            }
        }

        ret.emplace_back(s.begin(), s.end());
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 3, 4, 1, 2, 3, 1};
        auto ret = findMatrix(nums);
        assert(ret.size() == 3);
        assert(ret[0].size() == 4);
        assert(ret[1].size() == 2);
        assert(ret[2].size() == 1);
    }
    {
        std::vector<int> nums{1, 2, 3, 4};
        auto ret = findMatrix(nums);
        assert(ret.size() == 1);
        assert(ret[0].size() == 4);
    }
    return 0;
}
