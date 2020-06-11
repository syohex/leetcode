#include <cassert>
#include <vector>

bool isMonotonic(const std::vector<int> &A) {
    enum Type {
        kUnknown,
        kIncrease,
        kDecrease,
    };

    Type t = kUnknown;
    for (size_t i = 0; i < A.size() - 1; ++i) {
        if (t == kUnknown) {
            if (A[i] > A[i + 1]) {
                t = kDecrease;
            } else if (A[i] < A[i + 1]) {
                t = kIncrease;
            }
        } else if (t == kIncrease) {
            if (A[i] > A[i + 1]) {
                return false;
            }
        } else {
            if (A[i] < A[i + 1]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    assert((isMonotonic(std::vector<int>{1, 2, 2, 3})));
    assert((isMonotonic(std::vector<int>{6, 5, 4, 4})));
    assert((!isMonotonic(std::vector<int>{1, 3, 2})));
    assert((isMonotonic(std::vector<int>{1, 2, 4, 5})));
    assert((isMonotonic(std::vector<int>{1, 1, 1})));
    return 0;
}
