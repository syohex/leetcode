#include <cassert>
#include <cstdio>
#include <cstdint>

bool isPerfectSquare(int num) {
    if (num == 1) {
        return true;
    }

    int left = 0;
    int right = num;
    while (left <= right) {
        int n = (left + right) / 2;

        int64_t square = static_cast<int64_t>(n) * n;
        if (square == num) {
            return true;
        }
        if (square > num) {
            right = n - 1;
        } else {
            left = n + 1;
        }
    }

    return false;
}

int main() {
    assert(isPerfectSquare(1));
    assert(isPerfectSquare(4));
    assert(isPerfectSquare(9));
    assert(isPerfectSquare(16));
    assert(isPerfectSquare(25));
    assert(!isPerfectSquare(14));
    return 0;
}
