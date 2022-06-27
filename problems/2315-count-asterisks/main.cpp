#include <cassert>
#include <string>

int countAsterisks(const std::string &s) {
    bool in_bars = false;
    int ret = 0;
    for (char c : s) {
        if (c == '|') {
            in_bars = !in_bars;
        } else if (c == '*') {
            if (!in_bars) {
                ++ret;
            }
        }
    }

    return ret;
}

int main() {
    assert(countAsterisks("l|*e*et|c**o|*de|") == 2);
    assert(countAsterisks("iamprogrammer") == 0);
    assert(countAsterisks("yo|uar|e**|b|e***au|tifu|l") == 5);
    return 0;
}