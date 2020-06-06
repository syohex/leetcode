#include <cassert>
#include <vector>
#include <cstdio>

std::vector<int> selfDividingNumbers(int left, int right) {
    std::vector<int> ret;

    for (int i = left; i <= right; ++i) {
        int val = i;
        bool ok = true;
        while (val > 0) {
            int digit = val % 10;
            if (digit == 0 || i % digit != 0) {
                ok = false;
                break;
            }

            val /= 10;
        }

        if (ok) {
            ret.push_back(i);
        }
    }

    return ret;
}

int main() {
    assert((selfDividingNumbers(1, 22) == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22}));
    return 0;
}
