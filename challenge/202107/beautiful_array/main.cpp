#include <cassert>
#include <vector>
#include <map>
#include <functional>
#include <cstdio>

std::vector<int> beautifulArray(int n) {
    std::map<int, std::vector<int>> cache;

    std::function<std::vector<int>(int m)> f;
    f = [&f, &cache](int m) -> std::vector<int> {
        if (cache.find(m) != cache.end()) {
            return cache[m];
        }

        if (m == 1) {
            return std::vector<int>{1};
        }

        std::vector<int> ret;

        for (int a : f((m + 1) / 2)) {
            ret.push_back(2 * a - 1);
        }

        for (int a : f(m / 2)) {
            ret.push_back(2 * a);
        }

        cache[m] = ret;
        return ret;
    };

    return f(n);
}

void check(const std::vector<int> &v) {
    int len = v.size();
    for (int i = 0; i < len - 2; ++i) {
        for (int k = i + 1; k < len - 1; ++k) {
            for (int j = k + 1; j < len; ++j) {
                if (2 * v[k] == v[i] + v[j]) {
                    printf("## invalid 2 * v[%d](%d) == v[%d](%d) + v[%d](%d", k, v[k], i, v[i], j, v[j]);
                    assert(false);
                }
            }
        }
    }
}

int main() {
    check(beautifulArray(4));
    check(beautifulArray(5));
    check(beautifulArray(9));
    return 0;
}
