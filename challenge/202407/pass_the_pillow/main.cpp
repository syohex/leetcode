#include <cassert>
#include <cstdio>

int passThePillow(int n, int times) {
    int mod = times % (2 * n - 2);
    if (mod >= n) {
        return n - (mod - n) - 1;
    } else {
        return 1 + mod;
    }
}

int main() {
    assert(passThePillow(4, 1) == 2);
    assert(passThePillow(4, 5) == 2);
    assert(passThePillow(4, 7) == 2);
    assert(passThePillow(4, 6) == 1);
    assert(passThePillow(3, 2) == 3);
    return 0;
}
