#include <cassert>
#include <vector>

int peakIndexInMountainArray(const std::vector<int> &A) {
    for (int i = 1; i < A.size() - 1; ++i) {
        if (A[i - 1] < A[i] && A[i] > A[i + 1]) {
            return i;
        }
    }
    return 0;
}

int main() {
    {
        std::vector<int> input{0, 1, 0};
        assert(peakIndexInMountainArray(input) == 1);
    }
    {
        std::vector<int> input{0, 2, 1, 0};
        assert(peakIndexInMountainArray(input) == 1);
    }
    return 0;
}
