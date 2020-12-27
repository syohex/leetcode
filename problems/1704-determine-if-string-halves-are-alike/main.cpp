#include <cassert>
#include <string>

bool halvesAreAlike(const std::string &s) {
    const auto f = [&s](size_t start, size_t end) -> int {
        int ret = 0;
        for (size_t i = start; i < end; ++i) {
            switch (s[i]) {
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
                ++ret;
                break;
            }
        }

        return ret;
    };

    size_t half = s.size() / 2;
    return f(0, half) == f(half, s.size());
}

int main() {
    assert(halvesAreAlike("book"));
    assert(!halvesAreAlike("textbook"));
    assert(!halvesAreAlike("MerryChristmas"));
    assert(halvesAreAlike("AbCdEfGh"));
    return 0;
}
