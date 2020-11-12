#include <cassert>
#include <functional>
#include <cstdio>
#include <cmath>
#include <climits>

double myPow(double x, int n) {
    std::function<double(double xx, int nn, double acc)> f;
    f = [&f](double xx, int nn, double acc) -> double {
        if (nn == 0) {
            return acc;
        }

        int next_n = nn >= 0 ? nn - 1 : nn + 1;
        double next_acc = nn >= 0 ? acc * xx : acc / xx;
        return f(xx, next_n, next_acc);
    };

    return f(x, n, 1);
}

double myPow2(double x, int n) {
    double ret = 1;
    while (n != 0) {
        if (n >= 0) {
            ret *= x;
            --n;
        } else {
            ret /= x;
            ++n;
        }
    }

    return ret;
}

double myPow3(double x, int n) {
    std::function<double(double x, int n)> f;
    f = [&f](double x, int n) -> double {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }

        double tmp = f(x, n / 2);
        double value = tmp * tmp;
        if (n % 2 != 0) {
            value *= x;
        }

        return value;
    };

    double ret = f(x, n);
    if (n < 0) {
        return 1.0 / ret;
    }

    return ret;
}

bool check(double a, double b) {
    return std::abs(a - b) < 0.0000001;
}

int main() {
    assert(check(myPow(2.0, 10), 1024));
    assert(check(myPow(2.1, 3), 9.261));
    assert(check(myPow(2.0, -2), 0.25));

    assert(check(myPow2(2.0, 10), 1024));
    assert(check(myPow2(2.1, 3), 9.261));
    assert(check(myPow2(2.0, -2), 0.25));

    assert(check(myPow3(2.0, 10), 1024));
    assert(check(myPow3(2.1, 3), 9.261));
    assert(check(myPow3(2.0, -2), 0.25));

    printf("1 ^ 1000000=%g\n", myPow2(1, 1000000));
    printf("1 ^ 1000000=%g\n", myPow3(1, INT_MAX));
    return 0;
}
