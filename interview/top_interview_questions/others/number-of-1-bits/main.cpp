#include <cassert>
#include <cstdint>

int hammingWeight(uint32_t n) {
    int ret = 0;
    while (n != 0) {
        n = n & (n - 1);
        ++ret;
    }

    return ret;
}

int main() {
    assert(hammingWeight(11) == 3);
    assert(hammingWeight(256) == 1);
    assert(hammingWeight(0xffffefff) == 31);
    return 0;
}
