#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

int maxLengthBetweenCharacters(const std::string &s) {
    int ret = -1;
    std::vector<int> v(26, -1);
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        size_t index = s[i] - 'a';
        if (v[index] == -1) {
            v[index] = i;
        } else {
            ret = std::max(ret, i - v[index] - 1);
        }
    }

    return ret;
}

int main() {
    assert(maxLengthBetweenCharacters("aa") == 0);
    assert(maxLengthBetweenCharacters("abca") == 2);
    assert(maxLengthBetweenCharacters("cbzxy") == -1);
    return 0;
}
