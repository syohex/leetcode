#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

int nthUglyNumber(int n) {
    std::vector<int> v(n, 0);
    v[0] = 1;

    int i = 1;
    int i2 = 0, i3 = 0, i5 = 0;
    while (i < n) {
        int v2 = 2 * v[i2];
        int v3 = 3 * v[i3];
        int v5 = 5 * v[i5];

        int min = std::min({v2, v3, v5});
        v[i] = min;
        ++i;

        if (min == v2) {
            ++i2;
        }
        if (min == v3) {
            ++i3;
        }
        if (min == v5) {
            ++i5;
        }
    }

    return v.back();
}

int main() {
    assert(nthUglyNumber(10) == 12);
    assert(nthUglyNumber(1) == 1);
    return 0;
}
