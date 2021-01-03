#include <cassert>
#include <functional>
#include <vector>
#include <cstdio>

int countArangement(int n) {
    int ret = 0;
    std::function<void(int m, std::vector<bool> &used)> f;
    f = [&f, &n, &ret](int m, std::vector<bool> &used) {
        if (m > n) {
            ++ret;
            return;
        }

        for (int i = 1; i <= n; ++i) {
            if (used[i - 1]) {
                continue;
            }

            if (i % m == 0 || m % i == 0) {
                used[i - 1] = true;
                f(m + 1, used);
                used[i - 1] = false;
            }
        }
    };

    std::vector<bool> used(n, false);
    f(1, used);
    return ret;
}

int main() {
    assert(countArangement(1) == 1);
    assert(countArangement(2) == 2);
    assert(countArangement(15) == 24679);
    return 0;
}
