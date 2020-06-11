#include <cassert>
#include <cstdio>
#include <cmath>

bool checkPerfectNumber(int num) {
    if (num == 1) {
        return false;
    }

    int sum = 1;
    int limit = static_cast<int>(sqrt(num));
    for (int i = 2; i <= limit; ++i) {
        if (num % i == 0) {
            if (i == num / i) {
                sum += i;
            } else {
                sum += i;
                sum += num / i;
            }
        }
    }

    return sum == num;
}

int main() {
    assert(checkPerfectNumber(6));
    assert(checkPerfectNumber(28));
    assert(checkPerfectNumber(496));
    assert(checkPerfectNumber(8128));
    assert(!checkPerfectNumber(1));
    return 0;
}
