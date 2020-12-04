#include <cassert>

int kthFactor(int n, int k) {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            ++count;
            if (count == k) {
                return i;
            }
        }
    }

    return -1;
}

int main() {
    assert(kthFactor(12, 3) == 3);
    assert(kthFactor(7, 2) == 7);
    assert(kthFactor(4, 4) == -1);
    assert(kthFactor(1, 1) == 1);
    assert(kthFactor(1000, 3) == 4);
    return 0;
}
