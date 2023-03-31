#include <cassert>
#include <vector>

std::vector<int> evenOddBit(int n) {
    std::vector<int> ret(2, 0);

    bool is_even = true;
    while (n > 0) {
        if (n % 2 == 1) {
            if (is_even) {
                ret[0]++;
            } else {
                ret[1]++;
            }
        }

        n /= 2;
        is_even = !is_even;
    }

    return ret;
}

int main() {
    assert((evenOddBit(17) == std::vector<int>{2, 0}));
    assert((evenOddBit(2) == std::vector<int>{0, 1}));
    return 0;
}
