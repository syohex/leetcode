#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

int largetstSumAfterKNegations(std::vector<int> &A, int K) {
    std::sort(A.begin(), A.end());

    int negatives = 0;
    size_t nonNegativePos = 0;
    for (size_t i = 0; i < A.size(); ++i) {
        if (A[i] >= 0) {
            nonNegativePos = i;
            break;
        }

        ++negatives;
    }

    if (negatives >= K) {
        int sum = 0;
        for (auto n : A) {
            if (K > 0 && n < 0) {
                sum += -n;
                --K;
            } else {
                sum += n;
            }
        }

        return sum;
    }

    int remain = K - negatives;
    int sum = 0;
    for (auto n : A) {
        sum += n >= 0 ? n : -n;
    }

    if (remain % 2 != 0) {
        if (nonNegativePos >= 1) {
            if (-A[nonNegativePos - 1] < A[nonNegativePos]) {
                sum += A[nonNegativePos - 1] * 2;
            } else {
                sum -= A[nonNegativePos] * 2;
            }
        } else {
            sum -= A[nonNegativePos] * 2;
        }
    }

    return sum;
}

int main() {
    {
        std::vector<int> input{2, -3, -1, 5, -4};
        assert(largetstSumAfterKNegations(input, 2) == 13);
    }
    {
        std::vector<int> input{4, 2, 3};
        assert(largetstSumAfterKNegations(input, 1) == 5);
    }
    {
        std::vector<int> input{3, -1, 0, 2};
        assert(largetstSumAfterKNegations(input, 3) == 6);
    }
    {
        std::vector<int> input{-8, 3, -5, -3, -5, -2};
        assert(largetstSumAfterKNegations(input, 6) == 22);
    }
    return 0;
}
