#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

int maxProduct(const std::vector<std::string> &words) {
    std::vector<std::set<char>> v;
    for (const auto &word : words) {
        std::set<char> s;
        for (char c : word) {
            s.insert(c);
        }
        v.push_back(s);
    }

    int ret = 0;
    int len = words.size();
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            bool ok = true;
            for (char c : v[i]) {
                if (v[j].find(c) != v[j].end()) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                ret = std::max(ret, static_cast<int>(words[i].size() * words[j].size()));
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> words{"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
        assert(maxProduct(words) == 16);
    }
    {
        std::vector<std::string> words{"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
        assert(maxProduct(words) == 4);
    }
    {
        std::vector<std::string> words{"a", "aa", "aaa", "aaaa"};
        assert(maxProduct(words) == 0);
    }
    return 0;
}
