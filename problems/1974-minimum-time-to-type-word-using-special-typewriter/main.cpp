#include <cassert>
#include <string>
#include <algorithm>

int minTimeToType(const std::string &word) {
    int ret = 0;
    char current = 'a';
    for (char c : word) {
        int clockwise = c - current >= 0 ? c - current : c + 26 - current;
        int counter_clockwise = current - c > 0 ? current - c : current + 26 - c;

        ret += std::min(clockwise, counter_clockwise); // move
        ret += 1;                                      // type

        current = c;
    }

    return ret;
}

int main() {
    assert(minTimeToType("abc") == 5);
    assert(minTimeToType("bza") == 7);
    assert(minTimeToType("zjpc") == 34);
    assert(minTimeToType("aaa") == 3);
    return 0;
}