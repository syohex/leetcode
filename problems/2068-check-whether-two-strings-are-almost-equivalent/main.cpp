#include <cassert>
#include <string>
#include <vector>
#include <cmath>

bool checkAlmostEquivalent(const std::string &word1, const std::string &word2) {
    std::vector<int> v1(26, 0);
    std::vector<int> v2(26, 0);
    for (char c : word1) {
        ++v1[c - 'a'];
    }
    for (char c : word2) {
        ++v2[c - 'a'];
    }

    for (int i = 0; i < 26; ++i) {
        int diff = std::abs(v1[i] - v2[i]);
        if (diff > 3) {
            return false;
        }
    }
    return true;
}

int main() {
    assert(!checkAlmostEquivalent("aaaa", "bccb"));
    assert(checkAlmostEquivalent("abcdeef", "abaaacc"));
    assert(checkAlmostEquivalent("cccddabba", "babababab"));
    return 0;
}
