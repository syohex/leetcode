#include <cassert>
#include <string>

int getLucky(const std::string &s, int k) {
    std::string t;
    for (char c : s) {
        int v = c - 'a' + 1;
        t += std::to_string(v);
    }

    int ret = 0;
    for (int i = 0; i < k; ++i) {
        ret = 0;
        for (char c : t) {
            ret += c - '0';
        }
        t = std::to_string(ret);
        if (t.size() == 1) {
            break;
        }
    }

    return ret;
}

int main() {
    assert(getLucky("iiii", 1) == 36);
    assert(getLucky("leetcode", 2) == 6);
    assert(getLucky("zbax", 2) == 8);
    return 0;
}
