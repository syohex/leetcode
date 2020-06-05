#include <cassert>

int maximum69Number(int num) {
    int div = 1000;
    bool replaced = false;
    int ret = 0;
    while (div > 0) {
        int digit = num / div;
        if (digit == 0) {
            div /= 10;
            continue;
        }

        if (!replaced && digit == 6) {
            replaced = true;
            ret += 9 * div;
        } else {
            ret += digit * div;
        }

        num -= (digit * div);
        div /= 10;
    }

    return ret;
}

int main() {
    assert(maximum69Number(6) == 9);
    assert(maximum69Number(9) == 9);
    assert(maximum69Number(66) == 96);
    assert(maximum69Number(9669) == 9969);
    assert(maximum69Number(9996) == 9999);
    assert(maximum69Number(9999) == 9999);
    return 0;
}