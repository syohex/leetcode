#include <cassert>
#include <functional>

int countGoodNumbers(long long n) {
    long long odds = n / 2;
    long long evens = odds;

    if (n % 2 == 1) {
        ++evens;
    }

    static constexpr long long MOD = 1'000'000'007;
    std::function<long long(long long num, long long power)> f;
    f = [&f](long long num, long long power) -> long long {
        if (power == 0) {
            return 1;
        }
        if (power == 1) {
            return num;
        }

        auto powered = f(num, power / 2) % MOD;
        if (power % 2 == 0) {
            return (powered * powered) % MOD;
        }

        return (num % MOD * ((powered * powered) % MOD)) % MOD;
    };

    return ((f(5, evens) % MOD) * (f(4, odds) % MOD)) % MOD;
}

int main() {
    assert(countGoodNumbers(1) == 5);
    assert(countGoodNumbers(4) == 400);
    assert(countGoodNumbers(50) == 564908303);
    return 0;
}
