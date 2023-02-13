#include <cassert>

int countOdds(int low, int high) {
    bool low_is_odd = low % 2 == 1;
    bool high_is_odd = high % 2 == 1;

    int nums = high - low + 1;
    if (low_is_odd && high_is_odd) {
        return (nums / 2) + 1;
    }

    return nums / 2;
}

int main() {
    assert(countOdds(3, 7) == 3);
    assert(countOdds(8, 10) == 1);
    assert(countOdds(3, 8) == 3);
    assert(countOdds(4, 9) == 3);
    assert(countOdds(4, 4) == 0);
    assert(countOdds(9, 9) == 1);
    return 0;
}
