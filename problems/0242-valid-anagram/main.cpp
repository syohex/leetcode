#include <cassert>
#include <string>
#include <map>

bool isAnagram(const std::string &s, const std::string &t) {
    if (s.size() != t.size()) {
        return false;
    }

    std::map<char, int> sMap, tMap;
    for (size_t i = 0; i < s.size(); ++i) {
        ++sMap[s[i]];
        ++tMap[t[i]];
    }

    if (sMap.size() != tMap.size()) {
        return false;
    }

    for (const auto &it : sMap) {
        const auto tIt = tMap.find(it.first);
        if (tIt == tMap.end()) {
            return false;
        }

        if (it.second != tIt->second) {
            return false;
        }
    }

    return true;
}

int main() {
    assert(isAnagram("anagram", "nagaram"));
    assert(!isAnagram("rat", "car"));
    return 0;
}
