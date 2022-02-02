#include <cassert>
#include <vector>
#include <string>

std::vector<int> findAnagrams(const std::string &s, const std::string &p) {
    if (p.size() > s.size()) {
        return {};
    }

    std::vector<char> pv(26, 0);
    for (char c : p) {
        ++pv[c - 'a'];
    }

    std::vector<char> window(26, 0);

    int len = s.size();
    int len_p = p.size();
    for (int i = 0; i < len_p; ++i) {
        ++window[s[i] - 'a'];
    }

    std::vector<int> ret;
    if (window == pv) {
        ret.push_back(0);
    }

    for (int i = len_p; i < len; ++i) {
        --window[s[i - len_p] - 'a'];
        ++window[s[i] - 'a'];

        if (window == pv) {
            ret.push_back(i - len_p + 1);
        }
    }

    return ret;
}

int main() {
    {
        std::string s = "cbaebabacd";
        std::string p = "abc";
        std::vector<int> expected{0, 6};

        auto ret = findAnagrams(s, p);
        assert(ret == expected);
    }
    {
        std::string s = "abab";
        std::string p = "ab";
        std::vector<int> expected{0, 1, 2};

        auto ret = findAnagrams(s, p);
        assert(ret == expected);
    }
    return 0;
}
