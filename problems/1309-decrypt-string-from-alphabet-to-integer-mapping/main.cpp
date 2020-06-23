#include <cassert>
#include <string>
#include <algorithm>

std::string freqAlphabets(const std::string &s) {
    std::string ret;
    for (int i = static_cast<int>(s.size()) - 1; i >= 0;) {
        if (s[i] == '#') {
            char c = ((s[i - 2] - '0') * 10) + (s[i - 1] - '0') + 'a' - 1;
            ret.push_back(c);
            i -= 3;
        } else {
            char c = (s[i] - '0') + 'a' - 1;
            ret.push_back(c);
            --i;
        }
    }

    std::reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    assert(freqAlphabets("10#11#12") == "jkab");
    assert(freqAlphabets("1326#") == "acz");
    assert(freqAlphabets("25#") == "y");
    assert(freqAlphabets("12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#") == "abcdefghijklmnopqrstuvwxyz");
    return 0;
}
