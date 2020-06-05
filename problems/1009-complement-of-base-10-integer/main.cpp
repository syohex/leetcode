#include <cassert>
#include <vector>
#include <cstdio>

int bitwiseComplement(int N) {
    std::vector<int> b;

    while (N > 1) {
        b.push_back(N % 2 == 1 ? 1 : 0);
        N /= 2;
    }

    b.push_back(N == 1 ? 1 : 0);

    int ret = 0;
    int mul = 1;
    for (auto it = b.begin(); it != b.end(); ++it) {
        int val = *it == 0 ? 1 : 0;
        ret += mul * val;
        mul <<= 1;
    }

    return ret;
}

int main() {
    assert(bitwiseComplement(5) == 2);
    assert(bitwiseComplement(7) == 0);
    assert(bitwiseComplement(10) == 5);
    return 0;
}
