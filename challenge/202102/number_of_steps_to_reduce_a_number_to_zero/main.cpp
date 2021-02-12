#include <cassert>

int numberOfSteps(int num) {
    int count = 0;
    while (num != 0) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            --num;
        }

        ++count;
    }

    return count;
}

int main() {
    assert(numberOfSteps(14) == 6);
    assert(numberOfSteps(8) == 4);
    return 0;
}
