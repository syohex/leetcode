#include <cassert>
#include <string>
#include <map>

bool buddyStrings(const std::string &A, const std::string &B) {
    if (A.size() != B.size()) {
        return false;
    }

    size_t first;
    std::map<char, int> m;
    size_t diffs = 0;
    for (size_t i = 0; i < A.size(); ++i) {
        if (A[i] != B[i]) {
            if (diffs == 0) {
                first = i;
            } else {
                if (A[first] == A[i]) {
                    return false;
                }
                if (!(A[first] == B[i] && A[i] == B[first])) {
                    return false;
                }
            }
            ++diffs;
            if (diffs >= 3) {
                return false;
            }
        }
        ++m[A[i]];
    }

    if (diffs == 2) {
        return true;
    }
    if (diffs == 1) {
        return false;
    }

    for (const auto &it : m) {
        if (it.second >= 2) {
            return true;
        }
    }

    return false;
}

int main() {
    assert(buddyStrings("ab", "ba"));
    assert(!buddyStrings("ab", "ab"));
    assert(buddyStrings("aa", "aa"));
    assert(buddyStrings("aaaaaaabc", "aaaaaaacb"));
    assert(!buddyStrings("", "aa"));
    assert(!buddyStrings("abcaa", "abcbb"));
    assert(!buddyStrings("ab", "ca"));
    return 0;
}
