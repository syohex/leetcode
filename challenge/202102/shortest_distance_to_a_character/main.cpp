#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

std::vector<int> shortestToChar(const std::string &s, char c) {
    std::vector<int> ret;
    int len = s.size();
    int start = -1;
    for (int i = 0; i < len; ++i) {
        if (s[i] == c) {
            for (int j = start + 1; j < i; ++j) {
                if (start == -1) {
                    ret.push_back(i - j);
                } else {
                    ret.push_back(std::min(j - start, i - j));
                }
            }
            ret.push_back(0);
            start = i;
        }
    }

    for (int i = start + 1; i < len; ++i) {
        ret.push_back(i - start);
    }

    return ret;
}

int main() {
    {
        std::vector<int> expected{3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0};
        auto ret = shortestToChar("loveleetcode", 'e');
        assert(ret == expected);
    }
    {
        std::vector<int> expected{3, 2, 1, 0};
        auto ret = shortestToChar("aaab", 'b');
        assert(ret == expected);
    }
    return 0;
}
