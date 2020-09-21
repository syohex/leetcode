#include <cassert>
#include <string>
#include <vector>
#include <map>
#include <set>

bool wordPattern(const std::string &pattern, const std::string &s) {
    auto f = [](const std::string &str) -> std::vector<std::string> {
        std::vector<std::string> v;
        std::string tmp;

        for (const auto c : str) {
            if (c == ' ') {
                v.push_back(tmp);
                tmp.clear();
            } else {
                tmp.push_back(c);
            }
        }

        if (!tmp.empty()) {
            v.push_back(tmp);
        }

        return v;
    };

    auto words = f(s);
    if (words.size() != pattern.size()) {
        return false;
    }

    std::map<char, size_t> m;
    std::set<std::string> se;
    for (size_t i = 0; i < pattern.size(); ++i) {
        char key = pattern[i];
        if (m.find(key) == m.end()) {
            if (se.find(words[i]) != se.end()) {
                return false;
            }

            m[pattern[i]] = i;
            se.insert(words[i]);
        } else {
            if (words[m[key]] != words[i]) {
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
    return 0;
}
