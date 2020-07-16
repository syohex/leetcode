#include <cassert>
#include <string>
#include <vector>
#include <map>
#include <set>

bool wordPattern(const std::string &pattern, const std::string &str) {
    std::vector<std::string> v;
    std::string tmp;
    for (size_t i = 0; i < str.size();) {
        if (str[i] == ' ') {
            if (!tmp.empty()) {
                v.push_back(tmp);
                tmp.clear();
            }
            while (str[i] == ' ' && i < str.size()) {
                ++i;
            }
        } else {
            tmp.push_back(str[i]);
            ++i;
        }
    }

    if (!tmp.empty()) {
        v.push_back(tmp);
    }

    if (v.size() != pattern.size()) {
        return false;
    }

    std::map<char, int> m;
    std::map<int, std::string> table;
    std::set<std::string> words;
    int index = 0;
    for (size_t i = 0; i < pattern.size(); ++i) {
        if (m.find(pattern[i]) == m.end()) {
            if (words.find(v[i]) != words.end()) {
                return false;
            }
            table[index] = v[i];
            m[pattern[i]] = index++;
            words.insert(v[i]);
        } else {
            int idx = m[pattern[i]];
            if (v[i] != table[idx]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    assert(wordPattern("abba", "dog cat cat dog"));
    assert(!wordPattern("abba", "dog cat cat fish"));
    assert(!wordPattern("aaaa", "dog cat cat dog"));
    assert(!wordPattern("abba", "dog dog dog dog"));

    {
        std::string pattern("cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc"
                            "ccccccccccccccccccccccccccdd");
        std::string str("s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s "
                        "s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s s "
                        "s s s s s s s s s s s s s s s s s s s s s s t t");
        assert(wordPattern(pattern, str));
    }
    return 0;
}
