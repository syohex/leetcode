#include <cassert>
#include <vector>
#include <cmath>
#include <functional>

int totalNQueens(int n) {
    int ret = 0;
    std::function<void(int p, std::vector<int> &v)> f;
    f = [&f, &n, &ret](int p, std::vector<int> &v) {
        if (p == n) {
            ++ret;
            return;
        }

        for (int i = 0; i < n; ++i) {
            bool ok = true;
            for (int j = 0; j < p; ++j) {
                if (v[j] == i || std::abs(i - v[j]) == p - j) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                v[p] = i;
                f(p + 1, v);
            }
        }
    };

    std::vector<int> v(n);
    f(0, v);
    return ret;
}

int main() {
    assert(totalNQueens(4) == 2);
    assert(totalNQueens(1) == 1);
    assert(totalNQueens(10) == 724);
    return 0;
}