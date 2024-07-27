#include <cassert>
#include <string>

std::string losingPlayer(int x, int y) {
    bool is_even = true;
    while (true) {
        if (x >= 1 && y >= 4) {
            x -= 1;
            y -= 4;
            is_even = !is_even;
        } else {
            break;
        }
    }

    return is_even ? "Bob" : "Alice";
}

int main() {
    assert(losingPlayer(2, 7) == "Alice");
    assert(losingPlayer(4, 11) == "Bob");
    return 0;
}
