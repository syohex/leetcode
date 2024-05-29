#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

int numSteps(std::string s) {
    std::reverse(s.begin(), s.end());

    int len = s.size();
    for (int i = len - 1; i >= 0; --i) {
        if (s[i] == '1') {
            break;
        }
        s.pop_back();
    }

    len = s.size();
    int ret = 0;
    while (true) {
        if (len == 1 && s[0] == '1') {
            break;
        }

        if (s[0] == '0') {
            s = s.substr(1);
            --len;
        } else {
            int carry = 1;
            s[0] = '0';
            for (int i = 1; i < len; ++i) {
                if (s[i] == '1') {
                    s[i] = '0';
                } else {
                    s[i] = '1';
                    carry = 0;
                    break;
                }
            }
            if (carry == 1) {
                s.push_back('1');
                ++len;
            }
        }

        ++ret;
    }

    return ret;
}

int main() {
    assert(numSteps("1101") == 6);
    assert(numSteps("10") == 1);
    assert(numSteps("1") == 0);
    return 0;
}
