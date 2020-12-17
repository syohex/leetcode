#include <cassert>
#include <vector>
#include <map>

int fourSumCount(const std::vector<int> &A, const std::vector<int> &B, const std::vector<int> &C, const std::vector<int> &D) {
    std::map<int, int> m;
    for (const auto a : A) {
        for (const auto b : B) {
            ++m[a + b];
        }
    }

    int ret = 0;
    for (const auto c : C) {
        for (const auto d : D) {
            int diff = 0 - (c + d);
            if (m.find(diff) != m.end()) {
                ret += m[diff];
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> A{1, 2};
        std::vector<int> B{-2, -1};
        std::vector<int> C{-1, 2};
        std::vector<int> D{0, 2};
        assert(fourSumCount(A, B, C, D) == 2);
    }
    return 0;
}
