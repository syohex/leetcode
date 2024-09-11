#include <cassert>

int minBitFlips(int start, int goal) {
    int b = start ^ goal;
    b = (b & 0x55555555) + ((b >> 1) & 0x55555555);
    b = (b & 0x33333333) + ((b >> 2) & 0x33333333);
    b = (b & 0x0f0f0f0f) + ((b >> 4) & 0x0f0f0f0f);
    b = (b & 0x00ff00ff) + ((b >> 8) & 0x00ff00ff);
    b = (b & 0x0000ffff) + ((b >> 16) & 0x0000ffff);
    return b;
}

int main() {
    assert(minBitFlips(10, 7) == 3);
    assert(minBitFlips(3, 4) == 3);
    return 0;
}
