#include <cassert>
#include <cstdio>

int countOdds(int low, int high) {
    if (low == high) {
        return low % 2 == 1 ? 1 : 0;
    }

    bool a = low % 2 == 1;
    bool b = high % 2 == 1;
    if (a && b) {
        return (high - low + 1) / 2 + 1;
    } else {
        return (high - low + 1) / 2;
    }
}

int main() {
    assert(countOdds(3, 7) == 3);
    assert(countOdds(8, 10) == 1);
    assert(countOdds(8, 9) == 1);
    assert(countOdds(1, 10) == 5);
    assert(countOdds(0, 10) == 5);
    assert(countOdds(3, 3) == 1);
    assert(countOdds(2, 2) == 0);
    return 0;
}
