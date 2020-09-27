#include <cassert>
#include <vector>
#include <functional>
#include <cstdio>

std::vector<int> countBits(int num) {
    std::vector<int> ret;
    for (int i = 0; i <= num; ++i) {
        int j = i;
        int bits = 0;
        while (j > 0) {
            if ((j & 0x1) == 1) {
                ++bits;
            }

            j >>= 1;
        }

        ret.push_back(bits);
    }
    return ret;
}

int main() {
    assert((countBits(2) == std::vector<int>{0, 1, 1}));
    assert((countBits(5) == std::vector<int>{0, 1, 1, 2, 1, 2}));
    return 0;
}
