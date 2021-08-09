#include <cassert>
#include <string>
#include <algorithm>

std::string addStrings(const std::string &num1, const std::string &num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    int len = std::max(len1, len2);

    std::string ret;
    int carry = 0;
    for (int i = 0; i < len; ++i) {
        int index1 = len1 - 1 - i;
        int index2 = len2 - 1 - i;
        int n1 = index1 >= 0 ? num1[index1] - '0' : 0;
        int n2 = index2 >= 0 ? num2[index2] - '0' : 0;

        int n = n1 + n2 + carry;
        if (n >= 10) {
            carry = 1;
        } else {
            carry = 0;
        }

        ret.push_back(n % 10 + '0');
    }

    if (carry > 0) {
        ret.push_back(carry + '0');
    }

    std::reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    assert(addStrings("11", "123") == "134");
    assert(addStrings("456", "77") == "533");
    assert(addStrings("0", "0") == "0");
    assert(addStrings("1", "9") == "10");
    return 0;
}