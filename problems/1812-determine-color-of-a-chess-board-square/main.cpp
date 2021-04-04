#include <cassert>
#include <string>

bool squareIsWhite(const std::string &coordinates) {
    int first = coordinates[0] - 'a';
    int second = coordinates[1] - '1';

    bool is_first_odd = first % 2 == 1;
    bool is_second_odd = second % 2 == 1;

    return (is_first_odd && !is_second_odd) || (!is_first_odd && is_second_odd);
}

int main() {
    assert(!squareIsWhite("a1"));
    assert(squareIsWhite("h3"));
    assert(!squareIsWhite("c7"));
    return 0;
}