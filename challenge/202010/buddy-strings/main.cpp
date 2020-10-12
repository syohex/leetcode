#include <cassert>
#include <string>
#include <cstdio>
#include <map>
#include <vector>

bool buddyString(const std::string &A, const std::string &B) {
    if (A.size() != B.size()) {
        return false;
    }
    if (A.size() <= 1) {
        return false;
    }

    std::map<char, int> m;
    std::vector<std::vector<char>> v;
    int diffs = 0;
    for (size_t i = 0; i < A.size(); ++i) {
        if (A[i] == B[i]) {
            ++m[A[i]];
        } else {
            ++diffs;
            if (diffs >= 3) {
                return false;
            }

            v.push_back(std::vector<char>{A[i], B[i]});
        }
    }

    if (diffs > 0) {
        if (diffs == 1) {
            return false;
        }

        return v[0][0] == v[1][1] && v[0][1] == v[1][0];
    }

    for (const auto &it : m) {
        if (it.second >= 2) {
            return true;
        }
    }

    return false;
}

int main() {
    assert(buddyString("ab", "ba"));
    assert(!buddyString("ab", "ab"));
    assert(buddyString("aa", "aa"));
    assert(buddyString("aaaaaaabc", "aaaaaaacb"));
    assert(!buddyString("", "aa"));
    assert(!buddyString("abcaa", "abcbb"));
    return 0;
}
