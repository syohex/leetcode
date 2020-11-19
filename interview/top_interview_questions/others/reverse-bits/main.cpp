#include <cassert>
#include <cstdint>

uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0;
    uint32_t p = 31;
    while (n != 0) {
        ret += (n & 1) << p;
        n >>= 1;
        --p;
    }

    return ret;
}

int main() {
    assert(reverseBits(43261596) == 964176192);
    assert(reverseBits(4294967293) == 3221225471);
    assert(reverseBits(0) == 0);
    return 0;
}
