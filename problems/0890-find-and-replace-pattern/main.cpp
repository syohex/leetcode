#include <cassert>
#include <vector>
#include <string>
#include <functional>
#include <map>

std::vector<std::string> findAndReplacePattern(const std::vector<std::string> &words, const std::string &pattern) {
    struct CharPattern {
        int index = -1;
        int count = 1;

        bool operator==(const CharPattern &other) const noexcept {
            return index == other.index && count == other.count;
        }
    };

    const auto f = [](const std::string &p) -> std::vector<CharPattern> {
        std::vector<CharPattern> v;
        char prev = p[0];
        int count = 1;
        std::map<char, int> posMap{
            {prev, 0},
        };

        for (size_t i = 1; i < p.size(); ++i) {
            int index;
            auto it = posMap.find(p[i]);
            if (it == posMap.end()) {
                index = -1;
                posMap[p[i]] = i;
            } else {
                index = it->second;
            }

            if (p[i] != prev) {
                v.push_back(CharPattern{index, count});
                count = 1;
                prev = p[i];
            } else {
                ++count;
            }
        }

        if (count != 1) {
            auto it = posMap.find(prev);
            int index = it == posMap.end() ? -1 : it->second;
            v.push_back(CharPattern{index, count});
        }

        return v;
    };

    const auto patternSeq = f(pattern);
    std::vector<std::string> ret;
    for (const auto &word : words) {
        if (patternSeq == f(word)) {
            ret.push_back(word);
        }
    }
    return ret;
}

int main() {
    {
        std::vector<std::string> input{"abc", "deq", "mee", "aqq", "dkb", "ccc"};
        auto ret = findAndReplacePattern(input, "abb");
        assert((ret == std::vector<std::string>{"mee", "aqq"}));
    }
    {
        std::vector<std::string> input{"abc", "cba", "xyx", "yxx", "yyx"};
        auto ret = findAndReplacePattern(input, "abc");
        assert((ret == std::vector<std::string>{"abc", "cba"}));
    }
    {
        std::vector<std::string> input{"qqcojjumwp", "mqidrqudxu", "xwrvnueult", "lubbymxyro", "fcvxuskhcl"};
        auto ret = findAndReplacePattern(input, "rdzkpkbmda");
        assert((ret == std::vector<std::string>{}));
    }
    return 0;
}
