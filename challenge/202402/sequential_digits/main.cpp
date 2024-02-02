#include <cassert>
#include <vector>
#include <cstdio>

std::vector<int> sequencialDigits(int low, int high) {
    const auto digits = [](int n) {
        if (n == 0) {
            return 1;
        }

        int ret = 0;
        while (n > 0) {
            n /= 10;
            ++ret;
        }

        return ret;
    };

    const auto create_sequential_digit = [](int digit) -> std::vector<int> {
        std::vector<int> ret;
        for (int i = 1; i <= 10 - digit; ++i) {
            int num = i;
            for (int j = 1; j < digit; ++j) {
                num = num * 10 + i + j;
            }
            ret.push_back(num);
        }

        return ret;
    };

    int low_digits = digits(low);
    int high_digits = digits(high);

    std::vector<int> ret;
    for (int i = low_digits; i <= high_digits; ++i) {
        auto seqs = create_sequential_digit(i);
        for (int n : seqs) {
            if (n >= low && n <= high) {
                ret.push_back(n);
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> expected{123, 234};
        auto ret = sequencialDigits(100, 300);
        assert(ret == expected);
    }
    {
        std::vector<int> expected{1234, 2345, 3456, 4567, 5678, 6789, 12345};
        auto ret = sequencialDigits(1000, 13000);
        assert(ret == expected);
    }
    return 0;
}
