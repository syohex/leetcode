#include <cassert>
#include <vector>
#include <map>
#include <cstdio>

int minIncrementForUnique(const std::vector<int> &nums) {
    std::map<int, int> m;
    for (int num : nums) {
        ++m[num];
    }

    int ret = 0;
    for (int i = m.begin()->first; i <= m.rbegin()->first; ++i) {
        int v = m[i];
        if (v <= 1) {
            continue;
        }

        ret += v - 1;
        m[i + 1] += v - 1;
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 2, 2};
        int ret = minIncrementForUnique(nums);
        assert(ret == 1);
    }
    {
        std::vector<int> nums{3, 2, 1, 2, 1, 7};
        int ret = minIncrementForUnique(nums);
        assert(ret == 6);
    }
    return 0;
}
