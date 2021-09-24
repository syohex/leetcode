#include <cassert>

int tribonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1 || n == 2) {
        return 1;
    }

    int v0 = 0;
    int v1 = 1;
    int v2 = 1;
    int ret = 0;
    for (int i = 3; i <= n; ++i) {
        ret = v0 + v1 + v2;
        v0 = v1;
        v1 = v2;
        v2 = ret;
    }

    return ret;
}

int main() {
    assert(tribonacci(3) == 2);
    assert(tribonacci(4) == 4);
    assert(tribonacci(25) == 1389537);
    return 0;
}