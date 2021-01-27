#include <cassert>
#include <vector>
#include <cstdio>

int concatenatedBinary(int n) {
    std::vector<int> v;
    int tmp[32];
    for (int i = 1; i <= n; ++i) {
        int j = i;
        int p = 0;
        while (j > 0) {
            tmp[p++] = j % 2;
            j /= 2;
        }

        for (int k = p - 1; k >= 0; --k) {
            v.push_back(tmp[k]);
        }
    }

    constexpr int div = 1'000'000'000 + 7;
    int sum = 0;
    for (const auto i : v) {
        sum = ((sum << 1) + i) % div;
    }

    return sum;
}

int main() {
    assert(concatenatedBinary(1) == 1);
    assert(concatenatedBinary(3) == 27);
    assert(concatenatedBinary(12) == 505379714);
    return 0;
}
