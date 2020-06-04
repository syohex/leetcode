#include <cassert>
#include <string>

int strStr(const std::string &haystack, const std::string &needle) {
    if (needle.empty()) {
        return 0;
    }

    size_t size = needle.size();
    if (haystack.size() < needle.size()) {
        return -1;
    }
    if (haystack.size() == needle.size()) {
        return haystack == needle ? 0 : -1;
    }

    for (size_t i = 0; i < haystack.size(); ++i) {
        size_t j;
        for (j = 0; j < size; ++j) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }

        if (j == size) {
            return i;
        }
    }

    return -1;
}

int main(void) {
    assert(strStr("hello", "ll") == 2);
    assert(strStr("aaaaa", "bba") == -1);
    return 0;
}