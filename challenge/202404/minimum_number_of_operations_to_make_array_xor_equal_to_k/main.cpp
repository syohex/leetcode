#include <cassert>
#include <vector>

int minOperations(const std::vector<int> &nums, int k) {
    int v = 0;
    for (int num : nums) {
        v ^= num;
    }

    int ret = 0;
    while (v != 0 || k != 0) {
        if ((v & 1) != (k & 1)) {
            ++ret;
        }

        v >>= 1;
        k >>= 1;
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{2, 1, 3, 4};
        int ret = minOperations(nums, 1);
        assert(ret == 2);
    }
    {
        std::vector<int> nums{2, 0, 2, 0};
        int ret = minOperations(nums, 0);
        assert(ret == 0);
    }
    return 0;
}
