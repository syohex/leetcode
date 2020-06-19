#include <cassert>
#include <cmath>
#include <limits>

bool isPowerOfThree(int n) {
    if (n == 0) {
        return false;
    }
    if (n == 1) {
        return true;
    }

    while (n % 3 == 0) {
        n /= 3;
        if (n == 1) {
            return true;
        }
    }

    return false;
}

int main() {
    assert(isPowerOfThree(27));
    assert(!isPowerOfThree(0));
    assert(isPowerOfThree(9));
    assert(!isPowerOfThree(45));
    assert(isPowerOfThree(243));
    assert(!isPowerOfThree(19682));
    return 0;
}
