#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

std::string multiply(const std::string &num1, const std::string &num2) {
    std::vector<std::vector<int>> v;
    int num1_limit = static_cast<int>(num1.size() - 1);
    int num2_limit = static_cast<int>(num2.size() - 1);
    for (int i = num1_limit, count = 0; i >= 0; --i, ++count) {
        v.push_back(std::vector<int>{});
        for (int j = 0; j < count; ++j) {
            v[count].push_back(0);
        }

        int n1 = num1[i] - '0';
        int carry = 0;
        for (int j = num2_limit; j >= 0; --j) {
            int n2 = num2[j] - '0';
            int val = n1 * n2 + carry;
            carry = val / 10;
            v[count].push_back(val % 10);
        }
        if (carry != 0) {
            v[count].push_back(carry);
        }
    }

    std::string ret;
    size_t limit = v.back().size();
    int carry = 0;
    for (size_t i = 0; i < limit; ++i) {
        int sum = 0;
        for (size_t j = 0; j < v.size(); ++j) {
            int val = (i + 1 <= v[j].size()) ? v[j][i] : 0;
            sum += val;
        }

        sum += carry;
        ret.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    while (carry != 0) {
        ret.push_back(carry % 10 + '0');
        carry /= 10;
    }

    size_t zeros = 0;
    for (const char c : ret) {
        if (c == '0') {
            ++zeros;
        }
    }

    if (zeros == ret.size()) {
        return "0";
    }

    std::reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    assert(multiply("2", "3") == "6");
    assert(multiply("123", "456") == "56088");
    assert(multiply("123", "0") == "0");
    assert(multiply("0", "0") == "0");
    assert(multiply("123456789", "987654321") == "121932631112635269");
    assert(multiply("999999999999999999999", "99999999999999999999999") == "99999999999999999999899000000000000000000001");
    return 0;
}
