#include <cassert>
#include <string>

std::string maximumOddBinaryNumber(const std::string &s) {
    int zeros = 0;
    int ones = 0;

    for (char c : s) {
        if (c == '0') {
            ++zeros;
        } else {
            ++ones;
        }
    }

    std::string ret;
    while (ones > 1) {
        ret.push_back('1');
        --ones;
    }
    while (zeros > 0) {
        ret.push_back('0');
        --zeros;
    }

    ret.push_back('1');
    return ret;
}

int main() {
    assert(maximumOddBinaryNumber("010") == "001");
    assert(maximumOddBinaryNumber("0101") == "1001");
    return 0;
}
