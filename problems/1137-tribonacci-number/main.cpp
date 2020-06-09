#include <cassert>
#include <cstdio>

int tribonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 1;
    }

    int v2 = 0;
    int v1 = 1;
    int v0 = 1;

    n -= 3;
    int ret;
    while (n-- >= 0) {
        ret = v0 + v1 + v2;
        v2 = v1;
        v1 = v0;
        v0 = ret;
    }

    return ret;
}

int main() {
    assert(tribonacci(0) == 0);
    assert(tribonacci(1) == 1);
    assert(tribonacci(2) == 1);
    assert(tribonacci(3) == 2);
    assert(tribonacci(4) == 4);
    assert(tribonacci(25) == 1389537);
    return 0;
}
