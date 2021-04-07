#include <cassert>
#include <string>

bool halvesAreAlike(const std::string &s) {
    const auto f = [](const std::string &str, size_t start, size_t end) -> int {
        int count = 0;
        for (size_t i = start; i < end; ++i) {
            switch (str[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                ++count;
                break;
            default:
                break;
            }
        }

        return count;
    };

    size_t half = s.size() / 2;
    return f(s, 0, half) == f(s, half, s.size());
}

int main() {
    assert(halvesAreAlike("book"));
    assert(!halvesAreAlike("textbook"));
    assert(!halvesAreAlike("MerryChristmas"));
    assert(halvesAreAlike("AbCdEfGh"));
    return 0;
}
