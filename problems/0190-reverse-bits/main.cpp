#include <cassert>
#include <cinttypes>
#include <cstdio>
#include <vector>

uint32_t reverseBits(uint32_t n) {
    std::vector<int> v(32, 0);

    size_t pos = 0;
    while (true) {
        v[pos++] = n % 2;
        n /= 2;
        if (n == 0) {
            break;
        }
    }

    uint32_t ret = 0;
    for (size_t i = 0; i < 32; ++i) {
        ret += v[i];
        if (i != 31) {
            ret <<= 1;
        }
    }

    return ret;
}

int main() {
    assert(reverseBits(43261596) == 964176192);
    assert(reverseBits(4294967293) == 3221225471);
    return 0;
}
