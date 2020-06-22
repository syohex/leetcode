#include <cassert>
#include <cstdio>

int xorOperation(int n, int start) {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        ret ^= (start + (2 * i));
    }
    return ret;
}

int main() {
    assert(xorOperation(5, 0) == 8);
    assert(xorOperation(4, 3) == 8);
    assert(xorOperation(1, 7) == 7);
    assert(xorOperation(10, 5) == 2);
    return 0;
}
