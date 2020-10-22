#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstdio>

int minDominoRotations(const std::vector<int> &A, const std::vector<int> &B) {
    std::function<int(int val, const std::vector<int> &a, const std::vector<int> &b)> f;
    f = [&f](int val, const std::vector<int> &a, const std::vector<int> &b) {
        int limit = static_cast<int>(a.size());

        int rotate_a = 0, rotate_b = 0;
        for (int i = 0; i < limit; ++i) {
            if (val != a[i] && val != b[i]) {
                return -1;
            } else if (val != a[i]) {
                ++rotate_a;
            } else if (val != b[i]) {
                ++rotate_b;
            }
        }

        return std::min(rotate_a, rotate_b);
    };

    int ret_a = f(A[0], A, B);
    if (ret_a != -1 || A[0] == B[0]) {
        return ret_a;
    }

    return f(B[0], B, A);
}

int main() {
    {
        std::vector<int> a{2, 1, 2, 4, 2, 2};
        std::vector<int> b{5, 2, 6, 2, 3, 2};
        assert(minDominoRotations(a, b) == 2);
    }
    {
        std::vector<int> a{3, 5, 1, 2, 3};
        std::vector<int> b{3, 6, 3, 3, 4};
        assert(minDominoRotations(a, b) == -1);
    }
    return 0;
}
