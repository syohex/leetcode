#include <cassert>
#include <vector>
#include <cstdio>

int findComplement(int num) {
    std::vector<int> v;
    while (num > 0) {
        v.push_back(num % 2);
        num /= 2;
    }

    int ret = 0;
    int j = 1;
    for (const auto i : v) {
        int val = i == 1 ? 0 : 1;
        ret += val * j;
        j <<= 1;
    }

    return ret;
}

int main() {
    assert(findComplement(5) == 2);
    assert(findComplement(1) == 0);
    assert(findComplement(8) == 7);
    return 0;
}
