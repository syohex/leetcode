#include <cassert>
#include <vector>

long long zeroFilledSubarray(const std::vector<int> &nums) {
    long long ret = 0;
    long long sum = 0;
    for (int num : nums) {
        if (num == 0) {
            sum += 1;
        } else {
            sum = 0;
        }
        ret += sum;
    }
    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 3, 0, 0, 2, 0, 0, 4};
        auto ret = zeroFilledSubarray(nums);
        assert(ret == 6);
    }
    {
        std::vector<int> nums{0, 0, 0, 2, 0, 0};
        auto ret = zeroFilledSubarray(nums);
        assert(ret == 9);
    }
    return 0;
}
