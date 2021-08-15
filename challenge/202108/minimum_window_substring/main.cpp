#include <cassert>
#include <string>
#include <map>
#include <algorithm>

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

    int len = s.size();
    int left = 0;
    int right = 0;
    std::map<char, int> m;
    std::string ret(s);
    while (left < len && right < len) {
        while (right < len && !check(m, mt)) {
            ++m[s[right]];
            ++right;
        }

        if (!check(m, mt)) {
            break;
        }

        while (left < len) {
            char tmp = s[left];
            ++left;
            --m[tmp];
            if (m[tmp] < mt[tmp]) {
                break;
            }
        }

        int valid_len = right - left + 1;
        if (valid_len < static_cast<int>(ret.size())) {
            ret = s.substr(left - 1, valid_len);
        }
    }

    return ret;
}

int main() {
    assert(minWindow("ADOBECODEBANC", "ABC") == "BANC");
    assert(minWindow("a", "a") == "a");
    assert(minWindow("a", "aa") == "");
    return 0;
}