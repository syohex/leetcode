#include <cassert>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

bool isAlienSorted(const std::vector<std::string> &words, const std::string &order) {
    std::map<char, int> m;
    for (size_t i = 0; i < order.size(); ++i) {
        m[order[i]] = i;
    }

    auto v = words;
    const auto cmp = [&](const std::string &a, const std::string &b) -> bool {
        size_t len = std::min(a.size(), b.size());
        for (size_t i = 0; i < len; ++i) {
            if (a[i] != b[i]) {
                return m[a[i]] < m[b[i]];
            }
        }

        return a.size() < b.size();
    };

    std::sort(v.begin(), v.end(), cmp);

    return v == words;
}

int main() {
    {
        std::vector<std::string> words{"hello", "leetcode"};
        std::string order = "hlabcdefgijkmnopqrstuvwxyz";
        assert(isAlienSorted(words, order));
    }
    {
        std::vector<std::string> words{"word", "world", "row"};
        std::string order = "worldabcefghijkmnpqstuvxyz";
        assert(!isAlienSorted(words, order));
    }
    {
        std::vector<std::string> words{"apple", "app"};
        std::string order = "abcdefghijklmnopqrstuvwxyz";
        assert(!isAlienSorted(words, order));
    }
    return 0;
}
