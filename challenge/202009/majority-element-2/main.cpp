#include <cassert>
#include <vector>
#include <map>
#include <cstdio>

std::vector<int> majorityElement(const std::vector<int> &nums) {
    size_t n = nums.size() / 3;

    std::map<int, size_t> m;
    for (const auto num : nums) {
        ++m[num];
    }

    std::vector<int> ret;
    for (const auto &it : m) {
        if (it.second > n) {
            ret.push_back(it.first);
        }
    }
    return ret;
}

int main() {
    {
        std::vector<int> input{3, 2, 3};
        std::vector<int> expected{3};
        auto ret = majorityElement(input);
        assert(ret == expected);
    }
    {
        std::vector<int> input{1};
        std::vector<int> expected{1};
        auto ret = majorityElement(input);
        assert(ret == expected);
    }
    {
        std::vector<int> input{1, 2};
        std::vector<int> expected{1, 2};
        auto ret = majorityElement(input);
        assert(ret == expected);
    }
    return 0;
}
