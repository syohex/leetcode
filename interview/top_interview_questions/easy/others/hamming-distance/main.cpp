#include <cassert>
#include <cstdint>

int hammingDistance(int x, int y) {
    int ret = 0;
    int z = x ^ y;
    while (z != 0) {
        z = z & (z - 1);
        ++ret;
    }
    return ret;
}

int main() {
    assert(hammingDistance(1, 4) == 2);
    assert(hammingDistance(0xf, 0x7) == 1);
    assert(hammingDistance(0xf, 0x1) == 3);
    return 0;
}
