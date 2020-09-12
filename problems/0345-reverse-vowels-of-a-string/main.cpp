#include <cassert>
#include <string>
#include <cstdio>
#include <algorithm>

std::string reverseVowels(std::string &s) {
    if (s.size() <= 1) {
        return s;
    }

    auto is_vowel = [](char c) -> bool {
        return c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U';
    };

    int i = 0, j = static_cast<int>(s.size() - 1);
    while (i < j) {
        while (i < j) {
            if (is_vowel(s[i])) {
                break;
            }

            ++i;
        }

        while (i < j) {
            if (is_vowel(s[j])) {
                break;
            }

            --j;
        }

        if (i >= j) {
            break;
        }

        std::swap(s[i], s[j]);
        ++i;
        --j;
    }

    return s;
}

int main() {
    std::string input = "hello";
    assert(reverseVowels(input) == "holle");
    input = "leetcode";
    assert(reverseVowels(input) == "leotcede");
    input = "a";
    assert(reverseVowels(input) == "a");
    input = "bc";
    assert(reverseVowels(input) == "bc");
    input = "ai";
    assert(reverseVowels(input) == "ia");
    input = "aA";
    assert(reverseVowels(input) == "Aa");
    return 0;
}
