#include <cassert>
#include <string>
#include <algorithm>

std::string reverseStr(const std::string &s, int k) {
    std::string ret;
    for (int i = 0; i < s.size(); i += (2 * k)) {
        int limit = std::min(i + k, static_cast<int>(s.size())) - 1;
        for (int j = limit; j >= i; --j) {
            ret.push_back(s[j]);
        }

        int limit2 = std::min(i + 2 * k, static_cast<int>(s.size()));
        for (int j = limit + 1; j < limit2; ++j) {
            ret.push_back(s[j]);
        }
    }

    return ret;
}

int main() {
    {
        auto ret = reverseStr("abcdefg", 2);
        assert(ret == "bacdfeg");
    }
    {
        auto ret = reverseStr("abc", 2);
        assert(ret == "bac");
    }
    {
        auto ret = reverseStr("abcde", 10);
        assert(ret == "edcba");
    }

    return 0;
}
