#include <cassert>
#include <vector>
#include <map>

int duplicateNumbersXOR(const std::vector<int> &nums) {
    std::map<int, int> m;
    for (int num : nums) {
        ++m[num];
    }

    int ret = 0;
    for (const auto &[k, v] : m) {
        if (v >= 2) {
            ret ^= k;
        }
    }
    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 2, 1, 3};
        int ret = duplicateNumbersXOR(nums);
        assert(ret == 1);
    }
    {
        std::vector<int> nums{1, 2, 3};
        int ret = duplicateNumbersXOR(nums);
        assert(ret == 0);
    }
    {
        std::vector<int> nums{1, 2, 2, 1};
        int ret = duplicateNumbersXOR(nums);
        assert(ret == 3);
    }
    return 0;
}
