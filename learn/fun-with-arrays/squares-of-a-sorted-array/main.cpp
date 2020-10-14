#include <cassert>
#include <algorithm>
#include <vector>

std::vector<int> sortedSquare(std::vector<int> &A) {
    for (size_t i = 0; i < A.size(); ++i) {
        A[i] = A[i] * A[i];
    }

    std::sort(A.begin(), A.end());
    return A;
}

int main() {
    {
        std::vector<int> input{-4, -1, 0, 3, 10};
        auto ret = sortedSquare(input);
        assert((ret == std::vector<int>{0, 1, 9, 16, 100}));
    }
    {
        std::vector<int> input{-7, -3, 2, 3, 11};
        auto ret = sortedSquare(input);
        assert((ret == std::vector<int>{4, 9, 9, 49, 121}));
    }
    return 0;
}
