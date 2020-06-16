#include <cassert>
#include <vector>
#include <functional>
#include <cstdio>

int numSubarrayProductLessThanK(const std::vector<int> &nums, int k) {
    std::function<int(int, size_t)> f;
    f = [&f, &nums, &k](int product, size_t pos) -> int {
        if (pos >= nums.size()) {
            return 0;
        }

        int ret = 0;
        int p = product * nums[pos];
        if (p < k) {
            ++ret;
            ret += f(p, pos + 1);
        }

        return ret;
    };

    int ret = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        ret += f(1, i);
    }
    return ret;
}

int main() {
    {
        std::vector<int> input{10, 5, 2, 6};
        assert(numSubarrayProductLessThanK(input, 100) == 8);
    }
    return 0;
}
