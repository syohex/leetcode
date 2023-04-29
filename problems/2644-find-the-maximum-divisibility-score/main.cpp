#include <cassert>
#include <vector>

int maxDivScore(const std::vector<int> &nums, const std::vector<int> &divisors) {
    int ret = 1'000'000'009;
    int divs = 0;
    for (int d : divisors) {
        int ds = 0;
        for (int num : nums) {
            if (num % d == 0) {
                ++ds;
            }
        }

        if (ds > divs) {
            divs = ds;
            ret = d;
        } else if (ds == divs && d < ret) {
            ret = d;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{4, 7, 9, 3, 9};
        std::vector<int> divisors{5, 2, 3};
        int ret = maxDivScore(nums, divisors);
        assert(ret == 3);
    }
    {
        std::vector<int> nums{20, 14, 21, 10};
        std::vector<int> divisors{5, 7, 5};
        int ret = maxDivScore(nums, divisors);
        assert(ret == 5);
    }
    {
        std::vector<int> nums{12};
        std::vector<int> divisors{10, 16};
        int ret = maxDivScore(nums, divisors);
        assert(ret == 10);
    }
    return 0;
}
