#include <cassert>
#include <string>
#include <functional>
#include <map>

int numDecodings(const std::string &s) {
    std::map<size_t, int> cache;
    std::function<int(size_t pos)> f;

    f = [&f, &s, &cache](size_t pos) {
        if (pos == s.size()) {
            return 1;
        }

        if (s[pos] == '0') {
            return 0;
        }

        if (cache.find(pos) != cache.end()) {
            return cache[pos];
        }

        char c = s[pos];
        int ret = f(pos + 1);
        if (c == '1') {
            if (pos + 1 < s.size()) {
                ret += f(pos + 2);
            }
        } else if (c == '2') {
            if (pos + 1 < s.size()) {
                char c2 = s[pos + 1];
                if (c2 >= '0' && c2 <= '6') {
                    ret += f(pos + 2);
                }
            }
        }

        cache[pos] = ret;
        return ret;
    };

    return f(0);
}

int main() {
    assert(numDecodings("12") == 2);
    assert(numDecodings("226") == 3);
    assert(numDecodings("0") == 0);
    assert(numDecodings("1") == 1);

    return 0;
}
