#include <cassert>
#include <vector>

std::vector<int> plusOne(std::vector<int> &digits) {
    int carry = 1;
    for (int i = static_cast<int>(digits.size()) - 1; i >= 0 && carry == 1; --i) {
        int num = digits[i] + carry;
        if (num >= 10) {
            num %= 10;
            carry = 1;
        } else {
            carry = 0;
        }

        digits[i] = num;
    }

    if (carry == 0) {
        return digits;
    }

    std::vector<int> ret(digits.size() + 1);
    ret[0] = carry;
    for (size_t i = 0; i < digits.size(); ++i) {
        ret[i + 1] = digits[i];
    }
    return ret;
}

int main() {
    {
        std::vector<int> digits{1, 2, 3};
        std::vector<int> expected{1, 2, 4};
        assert(plusOne(digits) == expected);
    }
    {
        std::vector<int> digits{4, 3, 2, 1};
        std::vector<int> expected{4, 3, 2, 2};
        assert(plusOne(digits) == expected);
    }
    {
        std::vector<int> digits{0};
        std::vector<int> expected{1};
        assert(plusOne(digits) == expected);
    }
    {
        std::vector<int> digits{9};
        std::vector<int> expected{1, 0};
        assert(plusOne(digits) == expected);
    }
    return 0;
}
