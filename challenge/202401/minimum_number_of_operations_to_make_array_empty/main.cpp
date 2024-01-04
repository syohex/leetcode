#include <cassert>
#include <vector>
#include <map>

int minOperations(const std::vector<int> &nums) {
    std::map<int, int> m;
    for (int num : nums) {
        ++m[num];
    }

    int ret = 0;
    for (const auto &it : m) {
        if (it.second == 1) {
            return -1;
        }

        ret += it.second / 3;
        if (it.second % 3 != 0) {
            ret += 1;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{2, 3, 3, 2, 2, 4, 2, 3, 4};
        int ret = minOperations(nums);
        assert(ret == 4);
    }
    {
        std::vector<int> nums{2, 1, 2, 2, 3, 3};
        int ret = minOperations(nums);
        assert(ret == -1);
    }
    return 0;
}
