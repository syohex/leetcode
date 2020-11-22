#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> plusOne(const std::vector<int> &digits) {
    std::vector<int> ret;
    int carry = 1;
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
        int n = *it + carry;
        if (n >= 10) {
            n %= 10;
            carry = 1;
        } else {
            carry = 0;
        }

        ret.push_back(n);
    }

    if (carry == 1) {
        ret.push_back(1);
    }

    std::reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    {
        std::vector<int> digits{1, 2, 3};
        auto ret = plusOne(digits);
        assert((ret == std::vector<int>{1, 2, 4}));
    }
    {
        std::vector<int> digits{4, 3, 2, 1};
        auto ret = plusOne(digits);
        assert((ret == std::vector<int>{4, 3, 2, 2}));
    }
    {
        std::vector<int> digits{0};
        auto ret = plusOne(digits);
        assert((ret == std::vector<int>{1}));
    }
    {
        std::vector<int> digits{9};
        auto ret = plusOne(digits);
        assert((ret == std::vector<int>{1, 0}));
    }
    return 0;
}