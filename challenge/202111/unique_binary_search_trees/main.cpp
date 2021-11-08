#include <cassert>
#include <functional>
#include <map>

int numTrees(int n) {
    std::map<int, int> cache;

    std::function<int(int m)> f;
    f = [&](int m) -> int {
        if (m <= 1) {
            return 1;
        }
        if (cache.find(m) != cache.end()) {
            return cache[m];
        }

        int ret = 0;
        for (int i = 1; i <= m; ++i) {
            ret += f(i - 1) * f(m - i);
        }

        cache[m] = ret;
        return ret;
    };

    return f(n);
}

int main() {
    assert(numTrees(3) == 5);
    assert(numTrees(1) == 1);
    return 0;
}