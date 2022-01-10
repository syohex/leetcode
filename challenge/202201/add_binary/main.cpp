#include <cassert>
#include <string>
#include <algorithm>

std::string addBinary(const std::string &a, const std::string &b) {
    size_t len1 = a.size();
    size_t len2 = b.size();

    size_t pos = 0;
    std::string ret;
    int carry = 0;
    while (pos < len1 || pos < len2) {
        int v1 = pos < len1 ? a[len1 - 1 - pos] - '0' : 0;
        int v2 = pos < len2 ? b[len2 - 1 - pos] - '0' : 0;

        int v = v1 + v2 + carry;
        if (v >= 2) {
            v %= 2;
            carry = 1;
        } else {
            carry = 0;
        }

        ret.push_back(v + '0');
        ++pos;
    }

    if (carry == 1) {
        ret.push_back(carry + '0');
    }

    std::reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    assert(addBinary("11", "1") == "100");
    assert(addBinary("1010", "1011") == "10101");
    assert(addBinary("1111", "1") == "10000");
    return 0;
}
