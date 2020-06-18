#include <cassert>
#include <vector>
#include <algorithm>
#include <map>

std::vector<int> smallerNumbersThanCurrent(const std::vector<int> &nums) {
    std::vector<int> tmp(nums);
    std::sort(tmp.begin(), tmp.end());

    std::map<int, int> m;
    int prev = -1;
    int prevVal;
    for (size_t i = 0; i < tmp.size(); ++i) {
        if (tmp[i] != prev) {
            m[tmp[i]] = i;
            prevVal = i;
            prev = tmp[i];
        } else {
            m[tmp[i]] = prevVal;
        }
    }

    std::vector<int> ret(nums.size(), 0);
    for (size_t i = 0; i < nums.size(); ++i) {
        ret[i] = m[nums[i]];
    }

    return ret;
}

int main() {
    {
        std::vector<int> input{8, 1, 2, 2, 3};
        auto ret = smallerNumbersThanCurrent(input);
        assert((ret == std::vector<int>{4, 0, 1, 1, 3}));
    }
    {
        std::vector<int> input{6, 5, 4, 8};
        auto ret = smallerNumbersThanCurrent(input);
        assert((ret == std::vector<int>{2, 1, 0, 3}));
    }
    {
        std::vector<int> input{7, 7, 7, 7};
        auto ret = smallerNumbersThanCurrent(input);
        assert((ret == std::vector<int>{0, 0, 0, 0}));
    }
    return 0;
}
