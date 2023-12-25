#include <cassert>
#include <string>
#include <functional>
#include <map>

int numDecoding(const std::string &s) {
    std::function<int(size_t i, std::map<size_t, int> & cache)> f;
    f = [&](size_t i, std::map<size_t, int> &cache) -> int {
        if (i >= s.size()) {
            return 1;
        }

        if (cache.find(i) != cache.end()) {
            return cache[i];
        }

        if (s[i] == '0') {
            return 0;
        }

        int ret = f(i + 1, cache);
        if (i < s.size() - 1) {
            if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
                ret += f(i + 2, cache);
            }
        }

        cache[i] = ret;
        return ret;
    };

    std::map<size_t, int> cache;
    return f(0, cache);
}

int main() {
    assert(numDecoding("12") == 2);
    assert(numDecoding("226") == 3);
    assert(numDecoding("06") == 0);
    return 0;
}
