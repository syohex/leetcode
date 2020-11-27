#include <cassert>
#include <string>
#include <map>

bool isAnagram(const std::string &s, const std::string &t) {
    if (s.size() != t.size()) {
        return false;
    }

    std::map<char, int> ms, mt;
    for (size_t i = 0; i < s.size(); ++i) {
        ++ms[s[i]];
        ++mt[t[i]];
    }

    return ms == mt;
}

int main() {
    assert(isAnagram("anagram", "nagaram"));
    assert(!isAnagram("rat", "car"));
    assert(isAnagram("", ""));
    assert(isAnagram("a", "a"));
    return 0;
}
