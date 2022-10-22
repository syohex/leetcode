#include <cassert>
#include <string>
#include <map>

std::string minWindow(const std::string &s, const std::string &t) {
    const auto check = [](const std::map<char, int> &a, const std::map<char, int> &b) -> bool {
        for (const auto &it : b) {
            if (a.find(it.first) == a.end()) {
                return false;
            }

            if (a.at(it.first) < it.second) {
                return false;
            }
        }

        return true;
    };

    std::map<char, int> ms, mt;
    for (char c : s) {
        ++ms[c];
    }

    for (char c : t) {
        ++mt[c];
    }

    if (!check(ms, mt)) {
        return "";
    }

    int left = 0;
    int right = 0;
    int len = s.size();
    std::map<char, int> tmp;
    std::string ret = s;

    while (left < len && right < len) {
        while (right < len && !check(tmp, mt)) {
            ++tmp[s[right]];
            ++right;
        }

        if (!check(tmp, mt)) {
            break;
        }

        while (left < len) {
            char c = s[left];
            --tmp[c];
            ++left;

            if (tmp[c] < mt[c]) {
                break;
            }
        }

        int valid_len = right - left + 1;
        if (static_cast<size_t>(valid_len) < ret.size()) {
            ret = s.substr(left - 1, valid_len);
        }
    }

    return ret;
}

int main() {
    {
        std::string s = "ADOBECODEBANC";
        std::string t = "ABC";
        auto ret = minWindow(s, t);
        assert(ret == "BANC");
    }
    {
        std::string s = "a";
        std::string t = "a";
        auto ret = minWindow(s, t);
        assert(ret == "a");
    }
    {
        std::string s = "a";
        std::string t = "aa";
        auto ret = minWindow(s, t);
        assert(ret == "");
    }
    {
        std::string s = "acbdbaab";
        std::string t = "aabd";
        auto ret = minWindow(s, t);
        assert(ret == "dbaa");
    }
    return 0;
}