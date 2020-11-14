#include <cassert>
#include <functional>
#include <vector>
#include <cstdio>

int kthGrammer(int N, int K) {
    std::function<int(int val, int depth, const std::vector<int> &cols, int start, int end)> f;
    f = [&f](int val, int depth, const std::vector<int> &cols, int start, int end) {
        if (depth == static_cast<int>(cols.size())) {
            return val;
        }

        if (cols[depth] == start) {
            return f(val, depth + 1, cols, start * 2 - 1, start * 2);
        } else {
            return f(val == 1 ? 0 : 1, depth + 1, cols, end * 2 - 1, end * 2);
        }
    };

    std::vector<int> cols(N);
    int i = N - 1;
    int j = K;
    do {
        cols[i] = j;
        if (j % 2 == 0) {
            j /= 2;
        } else {
            j = (j + 1) / 2;
        }
        --i;
    } while (i >= 0);

    return f(0, 1, cols, 1, 2);
}

int main() {
    assert(kthGrammer(1, 1) == 0);
    assert(kthGrammer(2, 1) == 0);
    assert(kthGrammer(2, 2) == 1);
    assert(kthGrammer(4, 5) == 1);
    assert(kthGrammer(3, 2) == 1);
    assert(kthGrammer(3, 3) == 1);
    assert(kthGrammer(3, 1) == 0);
    return 0;
}