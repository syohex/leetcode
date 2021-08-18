#include <cassert>
#include <functional>
#include <string>

int numDecodings(const std::string &s) {
    int ret = 0;
    int len = s.size();
    std::function<void(int pos)> f;
    f = [&f, &s, &ret, &len](int pos) {
        if (pos == len) {
            ++ret;
            return;
        }

        if (pos == len - 1) {
            if (s[pos] == '0') {
                return;
            }

            f(pos + 1);
        } else {
            if (s[pos] == '0') {
                // do thing
            } else if (s[pos] == '1') {
                f(pos + 1);
                f(pos + 2);
            } else if (s[pos] == '2') {
                f(pos + 1);
                if (s[pos + 1] >= '0' && s[pos + 1] <= '6') {
                    f(pos + 2);
                }
            } else {
                f(pos + 1);
            }
        }
    };

    f(0);
    return ret;
}

int main() {
    assert(numDecodings("12") == 2);
    assert(numDecodings("226") == 3);
    assert(numDecodings("0") == 0);
    assert(numDecodings("06") == 0);
    return 0;
}
