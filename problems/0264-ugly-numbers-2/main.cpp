#include <cassert>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>

int nthUglyNumber(int n) {
    if (n == 1) {
        return 1;
    }

    std::vector<int> table(n, 0);
    table[0] = 1;

    int i = 1, i2 = 0, i3 = 0, i5 = 0;
    while (i < n) {
        int v1 = 2 * table[i2];
        int v2 = 3 * table[i3];
        int v3 = 5 * table[i5];

        int min = std::min({v1, v2, v3});
        table[i++] = min;
        if (min == v1) {
            ++i2;
        }
        if (min == v2) {
            ++i3;
        }
        if (min == v3) {
            ++i5;
        }
    }

    return table.back();
}

int main() {
    assert(nthUglyNumber(1) == 1);
    assert(nthUglyNumber(10) == 12);
    assert(nthUglyNumber(11) == 15);
    assert(nthUglyNumber(15) == 24);
    assert(nthUglyNumber(18) == 30);
    return 0;
}
