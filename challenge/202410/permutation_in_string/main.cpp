#include <cassert>
#include <string>
#include <vector>

bool checkInclusion(const std::string &s1, const std::string &s2) {
    int len1 = s1.size();
    int len2 = s2.size();

    if (len1 > len2) {
        return false;
    }

    std::vector<int> v1(26, 0);
    for (char c : s1) {
        ++v1[c - 'a'];
    }

    std::vector<int> window(26, 0);
    for (int i = 0; i < len1; ++i) {
        ++window[s2[i] - 'a'];
    }

    if (v1 == window) {
        return true;
    }

    for (int i = len1; i < len2; ++i) {
        --window[s2[i - len1] - 'a'];
        ++window[s2[i] - 'a'];

        if (v1 == window) {
            return true;
        }
    }
    return false;
}

int main() {
    assert(checkInclusion("ab", "eidbaooo"));
    assert(!checkInclusion("ab", "eidboaoo"));
    assert(checkInclusion("a", "ab"));
    assert(checkInclusion("ab", "b"));
    return 0;
}
