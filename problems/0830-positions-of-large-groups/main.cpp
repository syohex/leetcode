#include <cassert>
#include <string>
#include <vector>
#include <cstdio>

std::vector<std::vector<int>> largeGroupPositions(const std::string &s) {
    std::vector<std::vector<int>> ret;
    if (s.size() < 3) {
        return ret;
    }

    char prev = s[0];
    int start = 0;
    int count = 1;
    for (size_t i = 1; i < s.size(); ++i) {
        if (prev != s[i]) {
            if (count >= 3) {
                ret.push_back(std::vector<int>{start, static_cast<int>(i - 1)});
            }

            prev = s[i];
            count = 1;
            start = static_cast<int>(i);
            continue;
        }

        ++count;
    }

    if (count >= 3) {
        ret.push_back(std::vector<int>{start, static_cast<int>(s.size() - 1)});
    }

    return ret;
}

int main() {
    {
        auto ret = largeGroupPositions("abbxxxxzzy");
        assert(ret.size() == 1);
        assert((ret[0] == std::vector<int>{3, 6}));
    }
    {
        auto ret = largeGroupPositions("abc");
        assert(ret.empty());
    }
    {
        auto ret = largeGroupPositions("abcdddeeeeaabbbcd");
        assert(ret.size() == 3);
        assert((ret[0] == std::vector<int>{3, 5}));
        assert((ret[1] == std::vector<int>{6, 9}));
        assert((ret[2] == std::vector<int>{12, 14}));
    }
    {
        auto ret = largeGroupPositions("aba");
        assert(ret.empty());
    }
    {
        auto ret = largeGroupPositions("aaa");
        assert(ret.size() == 1);
        assert((ret[0] == std::vector<int>{0, 2}));
    }
    return 0;
}
