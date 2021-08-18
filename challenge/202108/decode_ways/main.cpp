#include <cassert>
#include <functional>
#include <string>
#include <map>

int numDecodings(const std::string &s) {
    int len = s.size();
    std::map<int, int> cache;
    std::function<int(int pos)> f;
    f = [&f, &s, &len, &cache](int pos) -> int {
        if (pos == len) {
            return 1;
        }

        if (cache.find(pos) != cache.end()) {
            return cache.at(pos);
        }

        int ret;
        if (s[pos] == '0') {
            ret = 0;
        } else {
            ret = f(pos + 1);

            if (pos < len - 1) {
                if (s[pos] == '1') {
                    ret += f(pos + 2);
                } else if (s[pos] == '2' && s[pos + 1] >= '0' && s[pos + 1] <= '6') {
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
    assert(numDecodings("06") == 0);
    assert(numDecodings("1201234") == 3);
    return 0;
}
