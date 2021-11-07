#include <cassert>
#include <string>
#include <vector>

std::string multiply(const std::string &num1, const std::string &num2) {
    std::vector<int> v1, v2;
    for (auto it = num1.rbegin(); it != num1.rend(); ++it) {
        v1.push_back(*it - '0');
    }
    for (auto it = num2.rbegin(); it != num2.rend(); ++it) {
        v2.push_back(*it - '0');
    }

    std::vector<int> ret(v1.size() + v2.size(), 0);
    for (size_t i = 0; i < v1.size(); ++i) {
        int a = v1[i];
        int carry = 0;
        for (size_t j = 0; j < v2.size(); ++j) {
            int b = v2[j];
            int mul = a * b;
            int digit = (mul % 10) + carry;
            if (digit >= 10) {
                carry = digit / 10;
                digit %= 10;
            } else {
                carry = 0;
            }

            carry += mul / 10;

            ret[i + j] += digit;
            if (ret[i + j] >= 10) {
                carry += ret[i + j] / 10;
                ret[i + j] %= 10;
            }
        }
        if (carry != 0) {
            ret[i + v2.size()] += carry;
        }
    }

    std::string s;
    bool leading_zero = true;
    for (auto it = ret.rbegin(); it != ret.rend(); ++it) {
        if (leading_zero) {
            if (*it == 0) {
                continue;
            }

            leading_zero = false;
        }
        s.push_back(*it + '0');
    }

    if (leading_zero) {
        return "0";
    }

    return s;
}

int main() {
    assert(multiply("2", "3") == "6");
    assert(multiply("123", "456") == "56088");
    assert(multiply("24165", "3841") == "92817765");
    assert(multiply("93818391283901820924165", "0") == "0");
    assert(multiply("2898129083", "812312809") == "2354187376256324147");
    return 0;
}