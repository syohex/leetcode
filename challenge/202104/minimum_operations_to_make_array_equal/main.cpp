#include <cassert>
#include <cstdio>

int minOperations(int n) {
    int limit = n / 2;
    int count = 0;
    int target = n;
    for (int i = 0; i < limit; ++i) {
        count += target - (2 * i + 1);
    }

    return count;
}

int main() {
    assert(minOperations(1) == 0);
    assert(minOperations(2) == 1);
    assert(minOperations(3) == 2);
    assert(minOperations(6) == 9);
    return 0;
}
