#include <cassert>
#include <string>

int getLucky(const std::string &s, int k) {
    int ret = 0;
    for (char c : s) {
        int v = c - 'a' + 1;
        while (v > 0) {
            ret += v % 10;
            v /= 10;
        }
    }

    for (int i = 0; i < k - 1; ++i) {
        int tmp = 0;
        while (ret > 0) {
            tmp += ret % 10;
            ret /= 10;
        }
        ret = tmp;
    }

    return ret;
}

int main() {
    assert(getLucky("iiii", 1) == 36);
    assert(getLucky("leetcode", 2) == 6);
    assert(getLucky("zbax", 2) == 8);
    return 0;
}