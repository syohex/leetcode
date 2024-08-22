#include <cassert>
#include <cstdio>

int findComplement(int num) {
    int ret = 0;
    int v = 1;
    while (num > 0) {
        int bit = num % 2 == 1 ? 0 : 1;
        ret = v * bit + ret;
        num >>= 1;
        v <<= 1;
    }
    return ret;
}

int main() {
    assert(findComplement(5) == 2);
    assert(findComplement(1) == 0);
    assert(findComplement(7) == 0);
    assert(findComplement(8) == 7);
    return 0;
}
