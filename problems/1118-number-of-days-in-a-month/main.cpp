#include <cassert>

int numberOfDays(int Y, int M) {
    static int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (M != 2) {
        return days[M - 1];
    }

    if (Y % 4 == 0) {
        if (Y % 400 == 0) {
            return 29;
        }

        if (Y % 100 == 0) {
            return 28;
        }

        return 29;
    }

    return 28;
}

int main() {
    assert(numberOfDays(1992, 7) == 31);
    assert(numberOfDays(2000, 2) == 29);
    assert(numberOfDays(1900, 2) == 28);
    return 0;
}
