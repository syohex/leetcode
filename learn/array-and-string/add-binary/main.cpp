#include <cassert>
#include <string>
#include <algorithm>

std::string addBinary(const std::string &a, const std::string &b) {
    int a_last = static_cast<int>(a.size() - 1);
    int b_last = static_cast<int>(b.size() - 1);
    int limit = std::max(a.size(), b.size());

    std::string ret(limit, 0);
    int carry = 0;
    for (int i = 0; i < limit; ++i) {
        int a_val = a_last - i >= 0 ? a[a_last - i] - '0' : 0;
        int b_val = b_last - i >= 0 ? b[b_last - i] - '0' : 0;

        int val = a_val + b_val + carry;
        if (val >= 2) {
            val = val % 2;
            carry = 1;
        } else {
            carry = 0;
        }

        ret[limit - i - 1] = val + '0';
    }

    if (carry != 0) {
        return std::to_string(carry) + ret;
    }

    return ret;
}

int main() {
    assert(addBinary("11", "1") == "100");
    assert(addBinary("1010", "1011") == "10101");
    assert(addBinary("1", "0") == "1");
    assert(addBinary("0", "0") == "0");
    assert(addBinary("10000", "0") == "10000");
    assert(addBinary("1111", "1111") == "11110");
    return 0;
}
