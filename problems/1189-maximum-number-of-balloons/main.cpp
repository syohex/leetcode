#include <cassert>
#include <string>
#include <map>

int maxNumberOfBalloons(const std::string &text) {
    std::map<char, int> m;
    for (char c : text) {
        ++m[c];
    }

    int ret = 0;
    while (true) {
        if (m['b'] >= 1 && m['a'] >= 1 && m['l'] >= 2 && m['o'] >= 2 && m['n'] >= 1) {
            m['b'] -= 1;
            m['a'] -= 1;
            m['l'] -= 2;
            m['o'] -= 2;
            m['n'] -= 1;
            ++ret;
            continue;
        }

        break;
    }

    return ret;
}

int main() {
    assert(maxNumberOfBalloons("nlaebolko") == 1);
    assert(maxNumberOfBalloons("loonbalxballpoon") == 2);
    assert(maxNumberOfBalloons("leetcode") == 0);
    return 0;
}
