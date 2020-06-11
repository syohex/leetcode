#include <cassert>

int fib(int N) {
    if (N == 0) {
        return 0;
    }
    if (N == 1) {
        return 1;
    }

    N -= 1;
    int a = 0;
    int b = 1;
    while (N >= 0) {
        if (N == 0) {
            return b;
        }

        int tmp = a;
        a = b;
        b = tmp + b;
        --N;
    }

    return 0;
}

int main() {
    assert(fib(0) == 0);
    assert(fib(1) == 1);
    assert(fib(2) == 1);
    assert(fib(3) == 2);
    assert(fib(4) == 3);
    return 0;
}
