#include <cassert>
#include <cstdint>

bool isPowerOfFour(int num) {
    if (num <= 0) {
        return false;
    }
    if ((num & (num - 1)) != 0) {
        return false;
    }

    return (static_cast<uint32_t>(num) & 0xAAAAAAAA) == 0x0;
}

int main() {
    assert(!isPowerOfFour(0));
    assert(isPowerOfFour(1));
    assert(!isPowerOfFour(2));
    assert(!isPowerOfFour(3));
    assert(isPowerOfFour(4));
    assert(!isPowerOfFour(5));
    assert(!isPowerOfFour(8));
    assert(isPowerOfFour(16));
    assert(!isPowerOfFour(20));
    assert(!isPowerOfFour(32));
    assert(isPowerOfFour(64));
    return 0;
}
