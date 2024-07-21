#include <cassert>

int minChanges(int n, int k) {
    int ret = 0;
    for (int i = 0, mask = 1; i < 32; ++i, mask <<= 1) {
        int a = n & mask;
        int b = k & mask;
        if (a != 0 && b == 0) {
            ++ret;
        } else if (a == 0 && b != 0) {
            return -1;
        }
    }

    return ret;
}

int main() {
    assert(minChanges(13, 4) == 2);
    assert(minChanges(21, 21) == 0);
    assert(minChanges(14, 13) == -1);
    return 0;
}
