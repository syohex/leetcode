#include <cassert>
#include <cstdio>
#include <cstdint>

int pick;

int guess(int num) {
    if (pick < num) {
        return -1;
    }
    if (pick > num) {
        return 1;
    }
    return 0;
}

int guessNumber(int n) {
    long left = 1;
    long right = n;
    while (left <= right) {
        long mid = (left + right) / 2;
        int ret = guess(mid);
        if (ret == 0) {
            return mid;
        }

        if (ret == 1) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    {
        pick = 6;
        int ret = guessNumber(10);
        assert(ret == pick);
    }
    {
        pick = 1;
        int ret = guessNumber(1);
        assert(ret == pick);
    }
    {
        pick = 1;
        int ret = guessNumber(2);
        assert(ret == pick);
    }
    {
        pick = 2;
        int ret = guessNumber(2);
        assert(ret == pick);
    }
}
