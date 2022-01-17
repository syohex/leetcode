#include <cassert>
#include <string>
#include <map>
#include <vector>
#include <set>

bool wordPattern(const std::string &pattern, const std::string &s) {
    std::vector<std::string> words;
    int len = s.size();
    int pos = 0;
    while (pos < len) {
        std::string tmp;
        while (pos < len && s[pos] != ' ') {
            tmp.push_back(s[pos]);
            ++pos;
        }
        words.push_back(tmp);
        ++pos;
    }

    if (pattern.size() != words.size()) {
        return false;
    }

    std::map<char, std::string> m;
    std::set<std::string> registered;
    for (size_t i = 0; i < pattern.size(); ++i) {
        if (m.find(pattern[i]) != m.end()) {
            if (m[pattern[i]] != words[i]) {
                return false;
            }
        } else {
            if (registered.find(words[i]) != registered.end()) {
                return false;
            }
            m[pattern[i]] = words[i];
            registered.insert(words[i]);
        }
    }

    return true;
}

int main() {
    assert(wordPattern("abba", "dog cat cat dog"));
    assert(!wordPattern("abba", "dog dog dog dog"));
    assert(!wordPattern("abba", "dog cat cat fish"));
    assert(!wordPattern("aaaa", "dog cat cat dog"));
    assert(!wordPattern("aaa", "aa aa aa aa"));
    return 0;
}
