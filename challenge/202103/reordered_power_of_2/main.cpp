#include <cassert>
#include <map>
#include <climits>
#include <cstdio>

bool reorderedPowerOf2(int N) {
    const auto f = [](long n) -> std::map<long, int> {
        std::map<long, int> m;
        while (n > 0) {
            long mod = n % 10;
            ++m[mod];
            n /= 10;
        }

        return m;
    };

    auto m = f(N);
    for (long i = 1; i < INT_MAX; i <<= 1) {
        auto n = f(i);
        if (m == n) {
            return true;
        }
    }

    return false;
}

int main() {
    assert(reorderedPowerOf2(1));
    assert(!reorderedPowerOf2(10));
    assert(reorderedPowerOf2(16));
    assert(!reorderedPowerOf2(24));
    assert(reorderedPowerOf2(46));
    assert(reorderedPowerOf2(56635));
    return 0;
}
