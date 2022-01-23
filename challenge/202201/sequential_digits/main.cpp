#include <cassert>
#include <vector>
#include <cstdio>

std::vector<int> sequentialDigits(int low, int high) {
    const auto digits = [](int n) -> int {
        if (n == 0) {
            return 1;
        }

        int ret = 0;
        while (n > 0) {
            ++ret;
            n /= 10;
        }

        return ret;
    };

    int start_digits = digits(low);
    int end_digits = digits(high);
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::vector<int> ret;
    for (int i = start_digits; i <= end_digits; ++i) {
        int limit = 10 - i;
        for (int j = 0; j < limit; ++j) {
            int num = 0;
            for (int k = 0; k < i; ++k) {
                num = num * 10 + v[k + j];
            }
            if (num >= low && num <= high) {
                ret.push_back(num);
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> expected{123, 234};
        auto ret = sequentialDigits(100, 300);
        assert(ret == expected);
    }
    {
        std::vector<int> expected{1234, 2345, 3456, 4567, 5678, 6789, 12345};
        auto ret = sequentialDigits(1000, 13000);
        assert(ret == expected);
    }
    return 0;
}
