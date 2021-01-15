#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

int getMaximumGenerated(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    std::vector<int> v(n + 1);
    v[0] = 0;
    v[1] = 1;

    int ret = 1;
    for (int i = 1; (2 * i) <= n; ++i) {
        v[2 * i] = v[i];
        ret = std::max(ret, v[2 * 1]);
        if (2 * i + 1 > n) {
            break;
        }

        v[2 * i + 1] = v[i] + v[i + 1];
        ret = std::max(ret, v[2 * i + 1]);
    }

    return ret;
}

int main() {
    assert(getMaximumGenerated(7) == 3);
    assert(getMaximumGenerated(1) == 1);
    assert(getMaximumGenerated(3) == 2);
    return 0;
}
