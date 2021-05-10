#include <cassert>
#include <vector>

int countPrimes(int n) {
    std::vector<bool> v(n + 1, true);
    v[0] = false;
    v[1] = false;

    int ret = 0;
    for (int i = 2; i < n; ++i) {
        if (v[i]) {
            for (int j = i * 2; j < n; j += i) {
                v[j] = false;
            }
            ++ret;
        }
    }

    return ret;
}

int main() {
    assert(countPrimes(10) == 4);
    assert(countPrimes(0) == 0);
    assert(countPrimes(1) == 0);
    assert(countPrimes(5000) == 669);
    assert(countPrimes(1000000) == 78498);
    return 0;
}
