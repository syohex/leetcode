#include <cassert>
#include <string>
#include <map>
#include <algorithm>

int firstUniqChar(const std::string &s) {
    if (s.empty()) {
        return -1;
    }

    struct Data {
        int index;
        int count;
    };

    std::map<char, Data> m;
    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        if (m.find(s[i]) == m.end()) {
            m[s[i]] = Data{i, 1};
        } else {
            m[s[i]].count++;
        }
    }

    int min = static_cast<int>(s.size());
    for (const auto &it : m) {
        if (it.second.count != 1) {
            continue;
        }

        min = std::min(min, it.second.index);
    }

    if (min == static_cast<int>(s.size())) {
        return -1;
    }

    return min;
}

int main() {
    assert(firstUniqChar("leetcode") == 0);
    assert(firstUniqChar("loveleetcode") == 2);
    assert(firstUniqChar("") == -1);
    assert(firstUniqChar("aaaaaaa") == -1);
    return 0;
}
