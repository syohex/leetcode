#include <cassert>
#include <string>

std::string addStrings(std::string num1, std::string num2) {
    if (num1.size() > num2.size()) {
        size_t diff = num1.size() - num2.size();
        num2 = std::string(diff, '0') + num2;
    } else if (num1.size() < num2.size()) {
        size_t diff = num2.size() - num1.size();
        num1 = std::string(diff, '0') + num1;
    }

    int carry = 0;
    std::string ret(num1.size(), '0');
    for (int i = static_cast<int>(num1.size()) - 1; i >= 0; --i) {
        int d1 = num1[i] - '0';
        int d2 = num2[i] - '0';

        int v = d1 + d2 + carry;
        if (v >= 10) {
            ret[i] = v % 10 + '0';
            carry = 1;
        } else {
            ret[i] = v + '0';
            carry = 0;
        }
    }

    if (carry == 1) {
        ret = std::string(1, '1') + ret;
    }

    return ret;
}

int main() {
    assert(addStrings("1", "1") == "2");
    assert(addStrings("1", "9") == "10");
    assert(addStrings("1234", "1234") == "2468");
    assert(addStrings("1", "9999") == "10000");
    return 0;
}
