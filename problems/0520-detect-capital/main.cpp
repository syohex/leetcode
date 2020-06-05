#include <cassert>
#include <string>

bool detectCapitalUse(const std::string &word) {
    bool first = word[0] >= 'A' && word[0] <= 'Z';

    bool hasUpper = false;
    bool hasLower = false;
    for (size_t i = 1; i < word.size(); ++i) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            if (!first) {
                return false;
            }
            if (hasLower) {
                return false;
            }

            hasUpper = true;
            continue;
        }

        if (first && hasUpper) {
            return false;
        }

        hasLower = true;
    }

    return true;
}

int main() {
    assert(detectCapitalUse("USA"));
    assert(!detectCapitalUse("FFFFFFFFFFFFFFFFFFFFf"));
    assert(detectCapitalUse("leetcode"));
    assert(detectCapitalUse("g"));
    assert(!detectCapitalUse("FlaG"));
    assert(detectCapitalUse("Google"));
    return 0;
}