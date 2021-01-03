#include <cassert>
#include <functional>
#include <set>
#include <cstdio>

int countArangement(int n) {
    int ret = 0;
    std::function<void(int m, std::set<int> used)> f;
    f = [&f, &n, &ret](int m, std::set<int> used) {
        if (m > n) {
            ++ret;
            return;
        }

        for (int i = 1; i <= n; ++i) {
            if (used.find(i) != used.end()) {
                continue;
            }

            if (i % m == 0 || m % i == 0) {
                auto tmp = used;
                tmp.insert(i);
                f(m + 1, tmp);
            }
        }
    };

    f(1, std::set<int>{});
    return ret;
}

int main() {
    assert(countArangement(1) == 1);
    assert(countArangement(2) == 2);
    assert(countArangement(15) == 2);
    return 0;
}
