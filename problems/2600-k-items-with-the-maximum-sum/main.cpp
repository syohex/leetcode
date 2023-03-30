#include <cassert>

int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
    if (numOnes >= k) {
        return k;
    }

    k -= numOnes;
    if (numZeros >= k) {
        return numOnes;
    }
    k -= numZeros;

    return numOnes - k;
}

int main() {
    assert(kItemsWithMaximumSum(3, 2, 0, 2) == 2);
    assert(kItemsWithMaximumSum(3, 2, 0, 4) == 3);
    assert(kItemsWithMaximumSum(1, 2, 3, 6) == -2);
    return 0;
}
