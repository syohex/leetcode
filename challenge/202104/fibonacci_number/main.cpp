#include <cassert>
#include <map>

std::map<int, int> cache;

int fib(int n) {
    if (cache.find(n) != cache.end()) {
        return cache[n];
    }

    if (n == 0) {
        cache[0] = 0;
        return 0;
    }

    if (n == 1) {
        cache[1] = 1;
        return 1;
    }

    int ret = fib(n - 1) + fib(n - 2);
    cache[n] = ret;
    return ret;
}

int main() {
    assert(fib(2) == 1);
    assert(fib(3) == 2);
    assert(fib(4) == 3);
    return 0;
}
