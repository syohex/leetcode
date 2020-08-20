#include <cassert>
#include <cstdio>

int minOperations(int n) {
    if (n == 1) {
        return 0;
    }

    int mid;
    if (n % 2 == 1) {
        mid = 2 * ((n - 2) / 2 + 1) + 1;
    } else {
        mid = (1 + (2 * (n - 1) + 1)) / 2;
    }

    int ret = 0;
    int limit = n / 2;
    for (int i = 0; i < limit; ++i) {
        ret += mid - (2 * i + 1);
    }

    return ret;
}

int main() {
    assert(minOperations(1) == 0);
    assert(minOperations(2) == 1);
    assert(minOperations(3) == 2);
    assert(minOperations(4) == 4);
    assert(minOperations(6) == 9);
    return 0;
}
