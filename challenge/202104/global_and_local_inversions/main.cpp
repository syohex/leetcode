#include <cassert>
#include <vector>

bool isIdealPermutation(const std::vector<int> &A) {
    int global = 0;
    int local = 0;

    int len = A.size();
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (A[i] > A[j]) {
                ++global;
            }
        }
    }

    for (int i = 0; i < len - 1; ++i) {
        if (A[i] > A[i + 1]) {
            ++local;
        }
    }

    return global == local;
}

int main() {
    assert((isIdealPermutation(std::vector<int>{1, 0, 2})));
    assert((!isIdealPermutation(std::vector<int>{1, 2, 0})));
    return 0;
}
