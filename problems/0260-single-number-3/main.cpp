#include <cassert>
#include <vector>
#include <queue>
#include <map>

std::vector<int> singleNumber(const std::vector<int> &nums) {
    std::map<int, int> m;
    for (const auto num : nums) {
        ++m[num];
    }

    std::vector<int> ret;
    for (const auto &it : m) {
        if (it.second != 2) {
            ret.push_back(it.first);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 2, 1, 3, 2, 5};
        auto ret = singleNumber(nums);
        assert((ret == std::vector<int>{3, 5}));
    }
    {
        std::vector<int> nums{-1, 0};
        auto ret = singleNumber(nums);
        assert((ret == std::vector<int>{-1, 0}));
    }
    {
        std::vector<int> nums{0, 1};
        auto ret = singleNumber(nums);
        assert((ret == std::vector<int>{0, 1}));
    }
    return 0;
}
