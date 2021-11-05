#include <cassert>

int arrangeCoins(int n) {
    int limit = n;
    for (int i = 1; i <= limit; ++i) {
        n -= i;
        if (n == 0) {
            return i;
        }
        if (n < 0) {
            return i - 1;
        }
    }

    return -1;
}

int main() {
    assert(arrangeCoins(1) == 1);
    assert(arrangeCoins(2) == 1);
    assert(arrangeCoins(5) == 2);
    assert(arrangeCoins(8) == 3);
    return 0;
}