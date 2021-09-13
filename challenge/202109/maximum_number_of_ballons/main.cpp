#include <cassert>
#include <string>
#include <map>

int maxNumberOfBallons(const std::string &text) {
    std::map<char, int> m;
    for (char c : text) {
        ++m[c];
    }

    int ret = 0;
    while (true) {
        if (m['a'] >= 1 && m['b'] >= 1 && m['l'] >= 2 && m['o'] >= 2 && m['n'] >= 1) {
            m['a'] -= 1;
            m['b'] -= 1;
            m['l'] -= 2;
            m['o'] -= 2;
            m['n'] -= 1;
            ++ret;
        } else {
            break;
        }
    }

    return ret;
}

int main() {
    assert(maxNumberOfBallons("nlaebolko") == 1);
    assert(maxNumberOfBallons("loonbalxballpoon") == 2);
    assert(maxNumberOfBallons("leetcode") == 0);
    return 0;
}