#include <cassert>
#include <string>
#include <cctype>

bool isValid(const std::string &word) {
    if (word.size() < 3) {
        return false;
    }

    bool has_vowel = false;
    bool has_consonant = false;
    for (char c : word) {
        char d = std::tolower(c);
        if (d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u') {
            has_vowel = true;
        } else if (d >= '0' && d <= '9') {
            // ok
        } else if (d == '@' || d == '#' || d == '$') {
            return false;
        } else {
            has_consonant = true;
        }
    }

    return has_vowel && has_consonant;
}

int main() {
    assert(isValid("234Adas"));
    assert(!isValid("b3"));
    assert(!isValid("a3$e"));
    return 0;
}
