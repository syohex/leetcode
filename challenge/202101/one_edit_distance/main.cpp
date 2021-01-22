#include <cassert>
#include <string>

bool isOneEditDistance(const std::string &s, const std::string &t) {
    if (s == t) {
        return false;
    }

    if (s.size() == t.size()) {
        int count = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] != t[i]) {
                ++count;
                if (count >= 2) {
                    return false;
                }
            }
        }

        return count == 1;
    }

    const std::string &s1 = s.size() > t.size() ? s : t;
    const std::string &s2 = s.size() > t.size() ? t : s;
    int count = 0;
    for (size_t i = 0, j = 0; i < s1.size(); ++i, ++j) {
        if (s1[i] != s2[j]) {
            ++count;
            if (count >= 2) {
                return false;
            }

            if (i < s1.size() - 1 && s1[i + 1] != s2[j]) {
                return false;
            }

            ++i;
        }
    }

    return true;
}

int main() {
    assert(isOneEditDistance("ab", "acb"));
    assert(!isOneEditDistance("", ""));
    assert(isOneEditDistance("a", ""));
    assert(isOneEditDistance("", "A"));
    assert(isOneEditDistance("ab", "abc"));
    assert(isOneEditDistance("abc", "ab"));
    return 0;
}
