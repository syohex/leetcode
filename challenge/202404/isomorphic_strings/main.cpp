#include <cassert>
#include <string>
#include <map>
#include <set>

bool isIsomorphic(const std::string &s, const std::string &t) {
    std::map<char, char> m;
    std::set<char> mapped;

    for (size_t i = 0; i < s.size(); ++i) {
        if (m.find(s[i]) != m.end()) {
            if (m[s[i]] != t[i]) {
                return false;
            }

            continue;
        }

        if (mapped.find(t[i]) != mapped.end()) {
            return false;
        }

        m[s[i]] = t[i];
        mapped.insert(t[i]);
    }

    return true;
}

int main() {
    assert(isIsomorphic("egg", "add"));
    assert(!isIsomorphic("foo", "bar"));
    assert(isIsomorphic("paper", "title"));
    assert(!isIsomorphic("bbbaaaba", "aaabbbba"));
    assert(!isIsomorphic("badc", "baba"));
    return 0;
}
