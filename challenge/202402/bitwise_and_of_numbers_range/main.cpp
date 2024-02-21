#include <cassert>

int rangeBitwiseAnd(int left, int right) {
    int shifts = 0;
    while (left != right) {
        left >>= 1;
        right >>= 1;

        ++shifts;
    }

    return left << shifts;
}

int main() {
    assert(rangeBitwiseAnd(5, 7) == 4);
    assert(rangeBitwiseAnd(0, 0) == 0);
    assert(rangeBitwiseAnd(1, 2147483647) == 0);
    assert(rangeBitwiseAnd(6, 7) == 6);
    return 0;
}
