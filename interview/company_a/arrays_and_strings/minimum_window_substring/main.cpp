#include <cassert>
#include <string>
#include <map>

std::string minWindow(const std::string &s, const std::string &t) {
    const auto check = [](const std::map<char, int> &ms, const std::map<char, int> &mt) {
        for (const auto &it : mt) {
            if (ms.find(it.first) == ms.end()) {
                return false;
            }

            if (it.second > ms.at(it.first)) {
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

    std::string ret = s;
    std::map<char, int> m;
    size_t start = 0, end = 0;
    size_t limit = s.size();
    while (start < limit && end < limit) {
        while (end < limit && !check(m, mt)) {
            ++m[s[end]];
            ++end;
        }

        if (!check(m, mt)) {
            break;
        }

        while (start < limit) {
            char c = s[start];
            ++start;
            --m[c];
            if (m[c] < mt[c]) {
                break;
            }
        }

        size_t len = end - start + 1;
        if (len < ret.size()) {
            ret = s.substr(start - 1, len);
        }
    }

    return ret;
}

int main() {
    assert(minWindow("ADOBECODEBANC", "ABC") == "BANC");
    assert(minWindow("A", "A") == "A");
    assert(minWindow("A", "AA") == "");
    assert(minWindow("acbdbaab", "aabd") == "dbaa");
    return 0;
}