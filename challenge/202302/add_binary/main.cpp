#include <cassert>
#include <string>
#include <algorithm>

std::string addBinary(const std::string &a, const std::string &b) {
    int len_a = a.size();
    int len_b = b.size();

    int carry = 0;
    std::string ret;
    for (int i = len_a - 1, j = len_b - 1; i >= 0 || j >= 0; --i, --j) {
        int v_a = i >= 0 ? a[i] - '0' : 0;
        int v_b = j >= 0 ? b[j] - '0' : 0;
        int v = v_a + v_b + carry;
        if (v == 3) {
            ret.push_back('1');
            carry = 1;
        } else if (v == 2) {
            ret.push_back('0');
            carry = 1;
        } else if (v == 1) {
            ret.push_back('1');
            carry = 0;
        } else {
            ret.push_back('0');
            carry = 0;
        }
    }

    if (carry == 1) {
        ret.push_back('1');
    }

    std::reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    assert(addBinary("11", "1") == "100");
    assert(addBinary("1010", "1011") == "10101");
    assert(addBinary("1", "1") == "10");
    assert(addBinary("1111", "1111") == "11110");
    return 0;
}
