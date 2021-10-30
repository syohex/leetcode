#include <cassert>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

std::string longestDupString(const std::string &s) {
    std::map<char, std::vector<size_t>> m;
    size_t len = s.size();
    for (size_t i = 0; i < len; ++i) {
        m[s[i]].push_back(i);
    }

    int max = 0;
    size_t max_pos = 0;
    for (size_t i = 0; i < len; ++i) {
        const auto &indexes = m[s[i]];
        for (size_t j : indexes) {
            if (j <= i) {
                continue;
            }

            int p = 1;
            while (j + p < len && s[i + p] == s[j + p]) {
                ++p;
            }

            if (p > max) {
                max = p;
                max_pos = i;
            }
        }
    }

    if (max == 0) {
        return "";
    }

    return s.substr(max_pos, max);
}

int main() {
    assert(longestDupString("banana") == "ana");
    assert(longestDupString("abcd") == "");
    return 0;
}