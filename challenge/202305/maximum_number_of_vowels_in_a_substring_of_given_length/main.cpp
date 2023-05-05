#include <cassert>
#include <string>
#include <algorithm>

int maxVowels(const std::string &s, int k) {
    int vowels = 0;
    int len = s.size();

    const auto is_vowel = [](char a) -> bool { return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'; };

    for (int i = 0; i < k; ++i) {
        if (is_vowel(s[i])) {
            vowels += 1;
        }
    }

    int ret = vowels;
    for (int i = k; i < len; ++i) {
        if (is_vowel(s[i - k])) {
            vowels -= 1;
        }
        if (is_vowel(s[i])) {
            vowels += 1;
        }
        ret = std::max(ret, vowels);
    }
    return ret;
}

int main() {
    assert(maxVowels("abciiidef", 3) == 3);
    assert(maxVowels("aeiou", 2) == 2);
    assert(maxVowels("leetcode", 3) == 2);
    return 0;
}
