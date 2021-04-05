#include <cassert>
#include <vector>
#include <algorithm>

bool isIdealPermutation(const std::vector<int> &A) {
    int max = A[0];
    int len = A.size();

    for (int i = 2; i < len; ++i) {
        if (max > A[i]) {
            return false;
        }

        max = std::max(max, A[i - 1]);
    }

    return true;
}

int main() {
    assert((isIdealPermutation(std::vector<int>{1, 0, 2})));
    assert((!isIdealPermutation(std::vector<int>{1, 2, 0})));
    return 0;
}
