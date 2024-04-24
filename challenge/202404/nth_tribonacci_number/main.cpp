#include <cassert>

int tribonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n <= 2) {
        return 1;
    }

    int prev3 = 0;
    int prev2 = 1;
    int prev1 = 1;
    int ret = 0;
    for (int i = 3; i <= n; ++i) {
        ret = prev1 + prev2 + prev3;
        prev3 = prev2;
        prev2 = prev1;
        prev1 = ret;
    }

    return ret;
}

int main() {
    assert(tribonacci(4) == 4);
    assert(tribonacci(25) == 1389537);
    return 0;
}
