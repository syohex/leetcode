#include <cassert>
#include <string>
#include <vector>
#include <cstdio>
#include <map>

std::string decodeMessage(const std::string &key, const std::string &message) {
    std::map<char, char> m;

    int i = 0;
    for (char c : key) {
        if (c == ' ') {
            continue;
        }

        if (m.find(c) == m.end()) {
            m[c] = 'a' + i;
            ++i;
        }
    }

    std::string ret;
    for (char c : message) {
        if (c == ' ') {
            ret.push_back(c);
        } else {
            ret.push_back(m[c]);
        }
    }
    return ret;
}

int main() {
    {
        std::string key("the quick brown fox jumps over the lazy dog");
        std::string message("vkbs bs t suepuv");
        auto ret = decodeMessage(key, message);
        assert(ret == "this is a secret");
    }
    {
        std::string key("eljuxhpwnyrdgtqkviszcfmabo");
        std::string message("zwx hnfx lqantp mnoeius ycgk vcnjrdb");
        auto ret = decodeMessage(key, message);
        assert(ret == "the five boxing wizards jump quickly");
    }
    return 0;
}
