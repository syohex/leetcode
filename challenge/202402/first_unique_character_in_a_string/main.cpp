#include <cassert>
#include <string>
#include <vector>
#include <cstdio>

int firstUniqChar(const std::string &s) {
    std::vector<int> v(26, -2);

    for (size_t i = 0; i < s.size(); ++i) {
        int index = s[i] - 'a';
        if (v[index] == -2) {
            v[index] = i;
        } else if (v[index] >= 0) {
            v[index] = -1;
        }
    }

    for (size_t i = 0; i < s.size(); ++i) {
        int index = s[i] - 'a';
        if (v[index] >= 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    assert(firstUniqChar("leetcode") == 0);
    assert(firstUniqChar("loveleetcode") == 2);
    assert(firstUniqChar("aabb") == -1);
    return 0;
}
