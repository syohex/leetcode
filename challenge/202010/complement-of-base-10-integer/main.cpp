#include <cassert>
#include <cstdio>

int bitwiseComplement(int N) {
    int orig = N;
    unsigned int digits = 1;
    while (N > 0) {
        N = N / 2;
        if (N == 0) {
            break;
        }
        ++digits;
    }

    int mask = (1u << digits) - 1;
    unsigned int ret = ~orig & mask;
    return static_cast<int>(ret);
}

int main() {
    assert(bitwiseComplement(5) == 2);
    assert(bitwiseComplement(7) == 0);
    assert(bitwiseComplement(10) == 5);
    assert(bitwiseComplement(0) == 1);
    assert(bitwiseComplement(1) == 0);
    return 0;
}
