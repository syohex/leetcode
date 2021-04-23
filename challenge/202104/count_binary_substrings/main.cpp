#include <cassert>
#include <string>

int countBinarySubstrings(const std::string& s) {
    int limit = s.size();
    int ret = 0;
    for (int i = 0; i < limit - 1;) {
        int j = i + 1;
        int count0 = 1;
        while (j < limit && s[i] == s[j]) {
            ++j;
            ++count0;
        }

        int tmp = j;
        int count1 = 0;
        while (j < limit && s[i] != s[j]) {
            ++count1;
            if (count0 == count1) {
                break;
            }
            ++j;
        }

        ret += count1;
        i = tmp;
    }

    return ret;
}

int main() {
    assert(countBinarySubstrings("00110011") == 6);
    assert(countBinarySubstrings("10101") == 4);
    assert(countBinarySubstrings("00110") == 3);
    return 0;
}
