#include <cassert>
#include <string>
#include <algorithm>
#include <cstdio>

std::string thousandSeparator(int n) {
    std::string ret;

    int digit = 0;
    while (true) {
        int m = n % 10;
        ret.push_back(m + '0');
        ++digit;

        n /= 10;
        if (n == 0) {
            break;
        }

        if (digit % 3 == 0) {
            ret.push_back('.');
        }
    }

    std::reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    assert(thousandSeparator(987) == "987");
    assert(thousandSeparator(1234) == "1.234");
    assert(thousandSeparator(123456789) == "123.456.789");
    assert(thousandSeparator(0) == "0");
    return 0;
}
