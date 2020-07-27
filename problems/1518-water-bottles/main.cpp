#include <cassert>
#include <cstdio>

int numWaterBottoles(int numBottles, int numExchange) {
    int sum = 0;
    int mod = 0;
    while (true) {
        sum += numBottles;
        int next = (numBottles + mod) / numExchange;
        if (next == 0) {
            return sum;
        }
        mod = (numBottles + mod) % numExchange;
        numBottles = next;
    }
}

int main() {
    assert(numWaterBottoles(9, 3) == 13);
    assert(numWaterBottoles(15, 4) == 19);
    assert(numWaterBottoles(5, 5) == 6);
    assert(numWaterBottoles(2, 3) == 2);
    return 0;
}
