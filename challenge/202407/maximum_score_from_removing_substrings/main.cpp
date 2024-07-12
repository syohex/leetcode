#include <cassert>
#include <string>

int maximumGain(std::string s, int x, int y) {
    const auto f = [](std::string &s, char first, char second, int score) -> int {
        int ret = 0;
        std::string buf;
        int len = s.size();

        int i = 0;
        while (i < len) {
            if (i >= len - 2 && s[i] == first && s[i + 1] == second) {
                ret += score;
                i += 2;
            } else if (!buf.empty() && buf.back() == first && s[i] == second) {
                ret += score;
                buf.pop_back();
                i += 1;
            } else {
                buf.push_back(s[i]);
                i += 1;
            }
        }

        s = buf;
        return ret;
    };

    int ret = 0;
    if (x > y) {
        ret += f(s, 'a', 'b', x);
        ret += f(s, 'b', 'a', y);
    } else {
        ret += f(s, 'b', 'a', y);
        ret += f(s, 'a', 'b', x);
    }

    return ret;
}

int main() {
    assert(maximumGain("cdbcbbaaabab", 4, 5) == 19);
    assert(maximumGain("aabbaaxybbaabb", 5, 4) == 20);
    return 0;
}
