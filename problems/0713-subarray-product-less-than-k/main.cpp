#include <cassert>
#include <vector>
#include <functional>
#include <cstdio>

int numSubarrayProductLessThanK(const std::vector<int> &nums, int k) {
    std::function<int(int, size_t)> f;
    int val;
    f = [&f, &nums, &k, &val](int product, size_t pos) -> int {
        int ret = 0;
        int p = product * nums[pos];
        if (p < k) {
            if (pos == nums.size() - 1) {
                val = p;
            }
            ++ret;

            for (size_t i = pos + 1; i < nums.size(); ++i) {
                if (nums[i] == 1) {
                    ++ret;
                } else {
                    ret += f(p, i);
                    break;
                }
            }
        }

        return ret;
    };

    int ret = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        val = 0;
        ret += f(1, i);
        if (val != 0 && val < k) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                ret += nums.size() - j;
            }
            break;
        }
    }
    return ret;
}

int main() {
    {
        std::vector<int> input{10, 5, 2, 6};
        assert(numSubarrayProductLessThanK(input, 100) == 8);
    }
    {
        std::vector<int> input{1, 1, 1};
        assert(numSubarrayProductLessThanK(input, 2) == 6);
    }
    return 0;
}
