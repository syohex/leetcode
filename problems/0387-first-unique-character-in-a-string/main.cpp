#include <cassert>
#include <string>
#include <map>
#include <climits>

int firstUniqChar(const std::string &s) {
    std::map<char, int> m;
    std::map<char, size_t> pos;
    for (size_t i = 0; i < s.size(); ++i) {
        if (pos.find(s[i]) == pos.end()) {
            pos[s[i]] = i;
        }

        ++m[s[i]];
    }

    size_t minPos = SIZE_MAX;
    for (const auto &it : m) {
        if (it.second == 1) {
            if (pos[it.first] < minPos) {
                minPos = pos[it.first];
            }
        }
    }

    if (minPos == SIZE_MAX) {
        return -1;
    }

    return static_cast<int>(minPos);
}

int main() {
    assert(firstUniqChar("leetcode") == 0);
    assert(firstUniqChar("loveleetcode") == 2);
    assert(firstUniqChar("aaaaaaaa") == -1);
    return 0;
}
