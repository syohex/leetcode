#include <cassert>
#include <vector>

int hammingDistance(int x, int y) {
    const auto f = [](unsigned int n) -> std::vector<int> {
        std::vector<int> ret;
        unsigned int j = 1;
        for (int i = 0; i < 32; ++i) {
            ret.push_back((n & j) != 0 ? 1 : 0);
            j <<= 1;
        }

        return ret;
    };

    auto a = f(x);
    auto b = f(y);

    int ret = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        if ((a[i] ^ b[i]) != 0) {
            ++ret;
        }
    }

    return ret;
}

int main() {
    assert(hammingDistance(1, 4) == 2);
    assert(hammingDistance(3, 1) == 1);
    return 0;
}