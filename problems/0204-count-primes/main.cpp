#include <cassert>
#include <vector>

int countPrimes(int n) {
    if (n < 2) {
        return 0;
    }
    if (n == 2) {
        return 0;
    }
    if (n == 3) {
        return 1;
    }

    std::vector<bool> primes(n, true);
    primes[0] = primes[1] = false;
    for (int i = 4; i < n; i += 2) {
        primes[i] = false;
    }
    for (int i = 3; i < n; i += 2) {
        if (!primes[i]) {
            continue;
        }

        for (int j = i * 2; j < n; j += i) {
            primes[j] = false;
        }
    }

    int ret = 0;
    for (const auto b : primes) {
        if (b) {
            ++ret;
        }
    }

    return ret;
}

int main() {
    assert((countPrimes(0) == 0));
    assert((countPrimes(1) == 0));
    assert((countPrimes(2) == 0));
    assert((countPrimes(3) == 1));
    assert((countPrimes(10) == 4));
    assert((countPrimes(100) == 25));
    assert((countPrimes(1000) == 168));
    return 0;
}
