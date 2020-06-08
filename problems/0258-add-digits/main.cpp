#include <cassert>
#include <cstdio>

int addDigits(int num) {
    int ret = 0;
    while (num > 0) {
        int digit = num % 10;
        ret += digit;
        num /= 10;
    }

    while (ret >= 10) {
        int digit = ret % 10;
        ret = (ret / 10) + digit;
    }

    return ret;
}

int main() {
    assert(addDigits(38) == 2);
    assert(addDigits(9) == 9);
    assert(addDigits(12345) == 6);
    return 0;
}
