#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

int firstUniqChar(const std::string &s) {
    struct Info {
        int count = 0;
        int pos = 0;
    };

    std::vector<Info> v(26);
    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        size_t index = s[i] - 'a';
        v[index].count++;
        v[index].pos = i;
    }

    int ret = INT_MAX;
    bool found = false;
    for (size_t i = 0; i < 26; ++i) {
        if (v[i].count == 1) {
            found = true;
            ret = std::min(ret, v[i].pos);
        }
    }

    if (!found) {
        return -1;
    }

    return ret;
}

int main() {
    assert(firstUniqChar("") == -1);
    assert(firstUniqChar("leetcode") == 0);
    assert(firstUniqChar("loveleetcode") == 2);
    assert(firstUniqChar("llll") == -1);
    return 0;
}
