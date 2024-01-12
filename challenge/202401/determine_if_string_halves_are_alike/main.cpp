#include <cassert>
#include <string>
#include <cctype>

bool halvesAreAlike(const std::string &s) {
    const auto isVowel = [](char c) -> bool {
        char a = std::tolower(c);
        return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
    };

    size_t half = s.size() / 2;
    int front = 0, back = 0;
    for (size_t i = 0; i < half; ++i) {
        if (isVowel(s[i])) {
            ++front;
        }
        if (isVowel(s[half + i])) {
            ++back;
        }
    }
    return front == back;
}

int main() {
    assert(halvesAreAlike("bool"));
    assert(!halvesAreAlike("textbook"));
    return 0;
}
