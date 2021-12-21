#include <cassert>

bool isPowerOfTwo(int n) {
    if (n <= 0) {
        return false;
    }

    bool has_one = false;
    while (n > 0) {
        if (n % 2 == 1) {
            if (has_one) {
                return false;
            }
            has_one = true;
        }

        n /= 2;
    }

    return has_one;
}

int main() {
    assert(isPowerOfTwo(1));
    assert(isPowerOfTwo(16));
    assert(!isPowerOfTwo(3));
    return 0;
}
