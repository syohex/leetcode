#include <cassert>
#include <vector>
#include <cstdio>

int distinctIntegers(int n) {
    std::vector<bool> prev(n + 1, false);
    std::vector<bool> cur(n + 1, false);

    prev[n] = true;

    while (true) {
        cur = prev;
        for (int i = 1; i <= n; ++i) {
            if (!cur[i]) {
                continue;
            }
            for (int j = 2; j < n; ++j) {
                if (i % j == 1) {
                    cur[j] = true;
                }
            }
        }

        if (cur == prev) {
            int ret = 0;
            for (int i = 1; i <= n; ++i) {
                if (cur[i]) {
                    ++ret;
                }
            }
            return ret;
        }

        prev = cur;
    }

    // never reach here
    return -1;
}

int main() {
    assert(distinctIntegers(5) == 4);
    assert(distinctIntegers(3) == 2);
    assert(distinctIntegers(1) == 1);
    return 0;
}
