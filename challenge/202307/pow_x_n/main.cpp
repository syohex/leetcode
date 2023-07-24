#include <cassert>
#include <cstdint>
#include <functional>
#include <cstdio>
#include <cmath>
#include <limits>

double myPow(double x, int n) {
    std::function<double(double x, int64_t n)> f;
    f = [&](double x, int64_t n) -> double {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }

        double v = f(x, n / 2);
        double ret = v * v;
        if (n % 2 == 1) {
            ret *= x;
        }

        return ret;
    };

    if (n >= 0) {
        return f(x, n);
    }

    double ret = f(x, -1 * static_cast<int64_t>(n));
    return 1.0 / ret;
}

int main() {
    const auto check = [](double a, double b) -> bool { return fabs(a - b) < std::numeric_limits<double>::epsilon(); };

    assert(check(myPow(2, 10), 1024));
    assert(check(myPow(2.1, 3), 9.26100));
    assert(check(myPow(2, -2), 0.25));
    return 0;
}
