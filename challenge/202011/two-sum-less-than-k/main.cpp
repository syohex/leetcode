#include <cassert>
#include <vector>
#include <algorithm>

int twoSumLessThanK(const std::vector<int> &A, int K) {
    if (A.size() <= 1) {
        return -1;
    }

    int ret = -1;
    for (size_t i = 0; i < A.size() - 1; ++i) {
        for (size_t j = i + 1; j < A.size(); ++j) {
            if (A[i] + A[j] < K) {
                ret = std::max(ret, A[i] + A[j]);
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> input{34, 23, 1, 24, 75, 33, 54, 8};
        assert(twoSumLessThanK(input, 60) == 58);
    }
    {
        std::vector<int> input{10, 20, 30};
        assert(twoSumLessThanK(input, 15) == -1);
    }
    return 0;
}
