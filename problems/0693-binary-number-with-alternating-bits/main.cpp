#include <cassert>
#include <cstdio>

bool hasAlternatingBits(int n) {
    int prev = static_cast<int>(n % 2 == 0);
    n /= 2;

    while (n > 0) {
        int bit = static_cast<int>(n % 2 == 0);
        if (prev == bit) {
            return false;
        }

        n /= 2;
        prev = bit;
    }

    return true;
}

int main() {
    assert(hasAlternatingBits(5));
    assert(!hasAlternatingBits(7));
    assert(!hasAlternatingBits(11));
    assert(hasAlternatingBits(10));
    return 0;
}
