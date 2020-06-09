#include <cassert>
#include <algorithm>
#include <vector>

void reverseString(std::vector<char> &s) {
    size_t size = s.size();
    size_t limit = size / 2;
    for (size_t i = 0; i < limit; ++i) {
        std::swap(s[i], s[size - 1 - i]);
    }
}

int main() {
    std::vector<char> input{'H', 'e', 'l', 'l', 'o'};
    reverseString(input);
    assert((input == std::vector<char>{'o', 'l', 'l', 'e', 'H'}));

    input = std::vector<char>{'H', 'a', 'n', 'n', 'a', 'h'};
    reverseString(input);
    assert((input == std::vector<char>{'h', 'a', 'n', 'n', 'a', 'H'}));

    input = std::vector<char>{'H'};
    reverseString(input);
    assert((input == std::vector<char>{'H'}));

    input = std::vector<char>{'a', 'b'};
    reverseString(input);
    assert((input == std::vector<char>{'b', 'a'}));
    return 0;
}
