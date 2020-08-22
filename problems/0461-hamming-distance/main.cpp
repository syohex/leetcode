#include <cassert>

int hammingDistance(int x, int y) {
    int z = x ^ y;
    int count = 0;
    while (z != 0) {
        int mod = z % 2;
        z = z / 2;
        count += mod;
    }

    return count;
}

int main() {
    assert(hammingDistance(1, 4) == 2);
    return 0;
}
