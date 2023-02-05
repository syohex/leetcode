#include <cassert>
#include <vector>
#include <string>

std::vector<int> findAnagrams(const std::string &s, const std::string &p) {
    int s_len = s.size();
    int p_len = p.size();
    if (p_len > s_len) {
        return {};
    }

    std::vector<int> p_table(26, 0);
    for (char c : p) {
        ++p_table[c - 'a'];
    }

    std::vector<int> window(26, 0);
    for (int i = 0; i < p_len; ++i) {
        ++window[s[i] - 'a'];
    }

    std::vector<int> ret;
    if (window == p_table) {
        ret.push_back(0);
    }

    for (int i = p_len; i < s_len; ++i) {
        --window[s[i - p_len] - 'a'];
        ++window[s[i] - 'a'];

        if (window == p_table) {
            ret.push_back(i - p_len + 1);
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
