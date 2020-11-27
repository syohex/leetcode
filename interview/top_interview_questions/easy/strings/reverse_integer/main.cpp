#include <cassert>
#include <climits>

int reverse(int x) {
    if (x == INT_MIN) {
        return 0;
    }

    bool minus = false;
    if (x < 0) {
        minus = true;
        x = -x;
    }

    int ret = 0;
    while (x != 0) {
        int n = x % 10;
        x /= 10;

        if (ret > (INT_MAX - n) / 10) {
            return 0;
        }

        ret = (ret * 10) + n;
    }

    if (minus) {
        ret *= -1;
    }

    return ret;
}

int main() {
    assert(reverse(321) == 123);
    assert(reverse(-123) == -321);
    assert(reverse(120) == 21);
    assert(reverse(0) == 0);
    assert(reverse(INT_MIN) == 0);
    assert(reverse(1534236469) == 0);
    return 0;
}
