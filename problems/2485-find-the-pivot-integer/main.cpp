#include <cassert>

int pivotInteger(int n) {
    int total = (n * (1 + n)) / 2;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
        if (sum == total - sum + i) {
            return i;
        }
    }

    return -1;
}

int main() {
    assert(pivotInteger(8) == 6);
    assert(pivotInteger(1) == 1);
    assert(pivotInteger(4) == -1);
    return 0;
}
