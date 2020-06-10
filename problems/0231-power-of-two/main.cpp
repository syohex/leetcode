#include <cassert>

bool isPowerOfTwo(int n) {
    if (n <= 0) {
        return false;
    }
    return (n & (n - 1)) == 0;
}

int main() {
    assert(!isPowerOfTwo(0));
    assert(isPowerOfTwo(1));
    assert(isPowerOfTwo(2));
    assert(!isPowerOfTwo(3));
    assert(isPowerOfTwo(4));
    assert(!isPowerOfTwo(5));
    return 0;
}
