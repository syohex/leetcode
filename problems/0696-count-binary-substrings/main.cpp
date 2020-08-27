#include <cassert>
#include <string>

int countBinarySubstrings(const std::string &s) {
    size_t limit = s.size();
    if (limit == 1) {
        return 0;
    }

    int ret = 0;
    for (size_t i = 0; i < limit - 1; ++i) {
        int count1 = 1;
        size_t j = i + 1;
        while (j < limit && s[i] == s[j]) {
            ++j;
            ++count1;
        }
        int count2 = 0;
        while (j < limit && s[i] != s[j]) {
            ++count2;
            if (count2 == count1) {
                ++ret;
                break;
            }
            ++j;
        }
    }
    return ret;
}

int main() {
    assert(countBinarySubstrings("00110011") == 6);
    assert(countBinarySubstrings("10101") == 4);
    assert(countBinarySubstrings("1") == 0);
    assert(countBinarySubstrings("10") == 1);
    return 0;
}
