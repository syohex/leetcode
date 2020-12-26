#include <cassert>
#include <string>
#include <functional>

int numDecodings(const std::string &s) {
    int ret = 0;
    std::function<void(size_t pos)> f;
    f = [&f, &ret, &s](size_t pos) {
        if (pos == s.size()) {
            ++ret;
            return;
        }

        char c = s[pos];
        if (c == '1') {
            f(pos + 1);
            if (pos + 1 < s.size()) {
                f(pos + 2);
            }
        } else if (c == '2') {
            f(pos + 1);

            if (pos + 1 < s.size()) {
                char c2 = s[pos + 1];
                if (c2 >= '0' && c2 <= '6') {
                    f(pos + 2);
                }
            }
        } else if (c >= '3' && c <= '9') {
            f(pos + 1);
        }
    };

    f(0);
    return ret;
}

int main() {
    assert(numDecodings("12") == 2);
    assert(numDecodings("226") == 3);
    assert(numDecodings("0") == 0);
    assert(numDecodings("1") == 1);

    return 0;
}
