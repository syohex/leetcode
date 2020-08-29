#include <cassert>
#include <string>
#include <vector>
#include <set>

bool repeatedSubstringPattern(const std::string &s) {
    if (s.size() <= 1) {
        return false;
    }

    std::vector<int> divs{1};
    int limit = static_cast<int>(s.size());
    for (int i = 2; i < limit; ++i) {
        if (limit % i == 0) {
            divs.push_back(i);
        }
    }

    for (auto it = divs.rbegin(); it != divs.rend(); ++it) {
        int div = *it;
        for (int j = 0; j < div; ++j) {
            for (int k = 1; k < limit / div; ++k) {
                if (s[j] != s[div * k + j]) {
                    goto next;
                }
            }
        }

        return true;
    next:;
    }

    return false;
}

int main() {
    assert(!repeatedSubstringPattern("a"));
    assert(repeatedSubstringPattern("abab"));
    assert(!repeatedSubstringPattern("aba"));
    assert(repeatedSubstringPattern("abcabcabcabc"));
    assert(repeatedSubstringPattern("ababab"));
    return 0;
}
