#include <cassert>
#include <cstdint>

int hammingWeight(uint32_t n) {
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
    n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
    n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
    return static_cast<int>(n);
}

int main() {
    assert(hammingWeight(11) == 3);
    assert(hammingWeight(0x000010000) == 1);
    assert(hammingWeight(0xFFFFFFEF) == 31);
    return 0;
}
