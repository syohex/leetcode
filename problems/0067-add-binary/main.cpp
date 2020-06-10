#include <cassert>
#include <string>
#include <algorithm>

std::string addBinary(const std::string &a, const std::string &b) {
    std::string ret;
    int idxA = static_cast<int>(a.size()) - 1;
    int idxB = static_cast<int>(b.size()) - 1;
    int carry = 0;
    for (; idxA >= 0 || idxB >= 0; --idxA, --idxB) {
        int valA = idxA >= 0 ? a[idxA] - '0' : 0;
        int valB = idxB >= 0 ? b[idxB] - '0' : 0;

        int val = valA + valB + carry;
        if (val >= 2) {
            ret.push_back((val & 0x1) + '0');
            carry = 1;
        } else {
            ret.push_back(val + '0');
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
    return 0;
}
