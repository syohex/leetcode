#include <cassert>
#include <string>
#include <cctype>

bool areNumbersAscending(const std::string &s) {
    size_t pos = 0;
    size_t limit = s.size();

    int prev = -1;
    while (pos < limit) {
        while (pos < limit && !std::isdigit(s[pos])) {
            ++pos;
        }

        if (pos >= limit) {
            break;
        }

        int num = s[pos] - '0';
        while (pos < limit && std::isdigit(s[pos])) {
            num = 10 * num + s[pos] - '0';
            ++pos;
        }

        if (num <= prev) {
            return false;
        }

        prev = num;
    }

    return true;
}

int main() {
    assert(areNumbersAscending("1 box has 3 blue 4 red 6 green and 12 yellow marbles"));
    assert(!areNumbersAscending("hello world 5 x 5"));
    assert(!areNumbersAscending("sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s"));
    assert(areNumbersAscending("4 5 11 26"));
    return 0;
}