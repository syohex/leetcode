#include <cassert>
#include <cstdio>

int numberOfSteps(int num) {
    if (num == 0) {
        return 0;
    }

    int steps = 0;
    while (num > 1) {
        if ((num & 0x1) == 0x0) {
            num >>= 1;
        } else {
            --num;
        }

        ++steps;
    }

    return steps + 1;
}

int main(void) {
    assert(numberOfSteps(0) == 0);
    assert(numberOfSteps(1) == 1);
    assert(numberOfSteps(2) == 2);
    assert(numberOfSteps(14) == 6);
    assert(numberOfSteps(8) == 4);
    assert(numberOfSteps(123) == 12);
    return 0;
}