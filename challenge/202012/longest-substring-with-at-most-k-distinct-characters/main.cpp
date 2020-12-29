#include <cassert>
#include <string>
#include <map>
#include <algorithm>

int lengthOfLongestSubstringKDistinct(const std::string &s, int k) {
    std::map<char, int> m;
    int ret = 0;

    int start = 0;
    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        ++m[s[i]];

        int chars = m.size();
        if (chars <= k) {
            ret = std::max(ret, i - start + 1);
        } else {
            for (int j = start; j < i; ++j) {
                --m[s[j]];
                if (m[s[j]] == 0) {
                    m.erase(s[j]);
                    start = j + 1;
                    break;
                }
            }
        }
    }

    return ret;
}

int main() {
    assert(lengthOfLongestSubstringKDistinct("eceba", 2) == 3);
    assert(lengthOfLongestSubstringKDistinct("aa", 1) == 2);
    assert(lengthOfLongestSubstringKDistinct("abaccc", 2) == 4);
    return 0;
}
