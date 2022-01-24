#include <cassert>
#include <string>
#include <algorithm>

bool detectCapitalUse(const std::string &word) {
    bool all_upper = std::all_of(word.begin(), word.end(), [](char c) { return c >= 'A' && c <= 'Z'; });
    if (all_upper) {
        return true;
    }

    bool all_lower = std::all_of(word.begin(), word.end(), [](char c) { return c >= 'a' && c <= 'z'; });
    if (all_lower) {
        return true;
    }

    if (word[0] >= 'a' && word[0] <= 'z') {
        return false;
    }

    return std::all_of(word.begin() + 1, word.end(), [](char c) { return c >= 'a' && c <= 'z'; });
}

int main() {
    assert(detectCapitalUse("USA"));
    assert(detectCapitalUse("Google"));
    assert(!detectCapitalUse("FlaG"));
    assert(detectCapitalUse("leetcode"));
    assert(!detectCapitalUse("FFFFFFFf"));
    assert(detectCapitalUse("g"));
    assert(detectCapitalUse("ggg"));
    return 0;
}
