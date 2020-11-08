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

    int ret = 0;
    std::vector<int> v{0, 1};
    for (int i = 2; i <= n; ++i) {
        int val;
        int idx = i / 2;
        if (i % 2 == 0) {
            val = v[idx];
        } else {
            val = v[idx] + v[idx + 1];
        }

        ret = std::max(ret, val);
        v.push_back(val);
    }

    return ret;
}

int main() {
    assert(getMaximumGenerated(7) == 3);
    assert(getMaximumGenerated(2) == 1);
    assert(getMaximumGenerated(3) == 2);
    return 0;
}
