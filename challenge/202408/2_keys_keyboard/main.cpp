#include <cassert>
#include <map>
#include <functional>
#include <algorithm>

int minSteps(int n) {
    std::map<std::pair<int, int>, int> cache;

    std::function<int(int v, int paste_size)> f;
    f = [&](int len, int paste_size) -> int {
        if (len == n) {
            return 0;
        }
        if (len > n) {
            return 1001;
        }

        std::pair<int, int> key{len, paste_size};
        if (cache.find(key) != cache.end()) {
            return cache[key];
        }

        int ret1 = 1 + f(len + paste_size, paste_size);
        int ret2 = 2 + f(2 * len, len);
        int ret = std::min(ret1, ret2);

        cache[key] = ret;
        return ret;
    };

    if (n == 1) {
        return 0;
    }

    return 1 + f(1, 1);
}

int main() {
    assert(minSteps(3) == 3);
    assert(minSteps(1) == 0);
    return 0;
}
