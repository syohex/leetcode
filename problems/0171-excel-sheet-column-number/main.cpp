#include <cassert>
#include <string>

int titleToNumber(const std::string &s) {
    int ret = 0;
    int base = 1;
    for (auto it = s.rbegin(); it != s.rend(); ++it, base *= 26) {
        ret += (*it - 'A' + 1) * base;
        if (it + 1 == s.rend()) {
            return ret;
        }
    }
    return ret;
}

int main() {
    assert(titleToNumber("A") == 1);
    assert(titleToNumber("AB") == 28);
    assert(titleToNumber("ZY") == 701);
    return 0;
}
