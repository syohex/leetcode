#include <cassert>
#include <cstdio>
#include <climits>

int divide(int dividend, int divisor) {
    long a = dividend;
    long b = divisor;

    if (a == INT_MIN && b == -1) {
        return INT_MAX;
    }

    if (b == 1) {
        return a;
    }

    bool negative = false;
    if (a < 0 && b < 0) {
        a *= -1;
        b *= -1;
    } else if (a < 0) {
        a *= -1;
        negative = true;
    } else if (divisor < 0) {
        b *= -1;
        negative = true;
    }

    int count = 0;
    while (a >= b) {
        a -= b;
        ++count;
    }

    if (negative) {
        count *= -1;
    }

    return count;
}

int main() {
    assert(divide(10, 3) == 3);
    assert(divide(7, -3) == -2);
    assert(divide(0, 1) == 0);
    assert(divide(1, 1) == 1);
    assert(divide(-1, -1) == 1);
    assert(divide(INT_MIN, -1) == INT_MAX);
    assert(divide(INT_MIN, 1) == INT_MIN);
    return 0;
}
