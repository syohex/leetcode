#include <cassert>
#include <cstdio>

int brokenCalc(int X, int Y) {
    int ret = 0;
    while (Y > X) {
        ++ret;
        if (Y % 2 == 1) {
            Y += 1;
        } else {
            Y /= 2;
        }
    }

    return ret + X - Y;
}

int main() {
    assert(brokenCalc(2, 3) == 2);
    assert(brokenCalc(5, 8) == 2);
    assert(brokenCalc(3, 10) == 3);
    assert(brokenCalc(1024, 1) == 1023);
    assert(brokenCalc(1, 1000000000) == 39);

    return 0;
}
