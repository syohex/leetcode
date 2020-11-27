#include <cassert>
#include <cmath>
#include <cstdio>

bool isPowerOfThree(int n) {
    if (n <= 0) {
        return false;
    }

    while (n >= 3) {
        if (n % 3 != 0) {
            return false;
        }

        n /= 3;
    }

    return n == 1;
}

int main() {
    assert(!isPowerOfThree(4));
    assert(!isPowerOfThree(5));
    assert(isPowerOfThree(27));
    assert(isPowerOfThree(81));
    assert(isPowerOfThree(243));
    assert(!isPowerOfThree(0));
    assert(isPowerOfThree(9));
    assert(!isPowerOfThree(45));
    assert(!isPowerOfThree(-3));
    assert(!isPowerOfThree(-27));
    return 0;
}
