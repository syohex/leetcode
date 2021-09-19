#include <cassert>
#include <string>
#include <functional>
#include <map>

int numDistinct(const std::string &s, const std::string &t) {
    std::map<std::pair<int, int>, int> cache;
    std::function<int(size_t i, size_t j)> f;
    f = [&](size_t i, size_t j) -> int {
        if (i >= s.size() || j >= t.size() || s.size() - i < t.size() - j) {
            if (j == t.size()) {
                return 1;
            }

            return 0;
        }

        std::pair<int, int> key{i, j};
        if (cache.find(key) != cache.end()) {
            return cache[key];
        }

        int ret = f(i + 1, j);
        if (s[i] == t[j]) {
            ret += f(i + 1, j + 1);
        }

        cache[key] = ret;
        return ret;
    };

    return f(0, 0);
}

int main() {
    assert(numDistinct("rabbbit", "rabbit") == 3);
    assert(numDistinct("babgbag", "bag") == 5);
    return 0;
}