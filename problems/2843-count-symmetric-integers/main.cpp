#include <cassert>

int countSymmetricIntegers(int low, int high) {
    int ret = 0;
    for (int i = low; i <= high; ++i) {
        if ((i >= 1 && i <= 9) || (i >= 100 && i <= 999)) {
            continue;
        }

        if (i >= 10 && i <= 99) {
            if (i / 10 == i % 10) {
                ++ret;
            }
        } else if (i >= 1000 && i <= 9999) {
            int a = i / 1000 + (i % 1000) / 100;
            int b = (i % 100) / 10 + i % 10;
            if (a == b) {
                ++ret;
            }
        }
    }

    return ret;
}

int main() {
    assert(countSymmetricIntegers(1, 100) == 9);
    assert(countSymmetricIntegers(1200, 1230) == 4);
    return 0;
}
