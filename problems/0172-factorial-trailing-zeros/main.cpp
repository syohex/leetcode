#include <cassert>
#include <cstdio>

int trailingZeroes(int n) {
    int ret = 0;
    for (int i = 5; i <= n; i += 5) {
        int j = i;
        while (j > 0) {
            if (j % 10 == 0) {
                ++ret;
                j /= 10;
                continue;
            }

            break;
        }
        while (j > 0) {
            if (j % 5 == 0) {
                ++ret;
                j /= 5;
                continue;
            }

            break;
        }
    }

    return ret;
}

int main() {
    assert(trailingZeroes(3) == 0);
    assert(trailingZeroes(5) == 1);
    assert(trailingZeroes(20) == 4);
    assert(trailingZeroes(100) == 24);
    assert(trailingZeroes(123) == 28);
    return 0;
}
