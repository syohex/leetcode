#include <string>
#include <cassert>

std::string reverseWords(const std::string &s) {
    std::string ret;
    for (int i = 0, start = 0; i < static_cast<int>(s.size()); ++i) {
        if (s[i] == ' ' || i + 1 == static_cast<int>(s.size())) {
            int k = s[i] == ' ' ? i - 1 : i;
            for (int j = k; j >= start; --j) {
                ret.push_back(s[j]);
            }

            if (s[i] == ' ') {
                ret.push_back(' ');
            }

            start = i + 1;
        }
    }

    return ret;
}

int main() {
    assert(reverseWords("apple") == "elppa");
    assert(reverseWords("hello world") == "olleh dlrow");
    assert(reverseWords("Let's take LeetCode contest") == "s'teL ekat edoCteeL tsetnoc");
    return 0;
}
