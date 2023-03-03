#include <cassert>
#include <string>
#include <vector>

int strStr(std::string haystack, std::string needle) {
    int m = needle.length();
    int n = haystack.length();

    if (n < m)
        return -1;

    std::vector<int> table(m);
    {
        int i = 1;
        int j = 0;

        while (i < m) {
            if (needle[i] == needle[j]) {
                j += 1;
                table[i] = j;
                i += 1;
            } else {
                if (j == 0) {
                    table[i] = 0;
                    i += 1;
                } else {
                    j = table[j - 1];
                }
            }
        }
    }


    int i = 0;
    int j = 0;
    while (i < n) {
        if (haystack[i] == needle[j]) {
            j += 1;
            i += 1;
            if (j == m) {
                return i - m;
            }
        } else {
            if (j == 0) {
                i += 1;
            } else {
                j = table[j - 1];
            }
        }
    }

    return -1;
}

int main() {
    assert(strStr("sadbutsad", "sad") == 0);
    assert(strStr("leetcode", "leeto") == -1);
    assert(strStr("babba", "bbb") == -1);
    return 0;
}
