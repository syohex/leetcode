#include <cassert>
#include <cstdio>

int numWaterBottles(int numBottles, int numExchange) {
    int ret = 0;
    int full_bottles = numBottles;
    int empty_bottles = 0;
    while (full_bottles > 0) {
        int next_full = (full_bottles + empty_bottles) / numExchange;
        empty_bottles = (full_bottles + empty_bottles) % numExchange;

        ret += next_full * numExchange;
        full_bottles = next_full;
    }
    ret += empty_bottles;

    return ret;
}

int main() {
    assert(numWaterBottles(9, 3) == 13);
    assert(numWaterBottles(15, 4) == 19);
    return 0;
}
