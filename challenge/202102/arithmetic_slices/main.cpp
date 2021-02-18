#include <cassert>
#include <vector>

int numberOfAnrithmeticSlices(const std::vector<int> &A) {
    int ret = 0;
    std::vector<int> dp(A.size(), 0);
    for (size_t i = 2; i < A.size(); ++i) {
        if (A[i - 2] - A[i - 1] == A[i - 1] - A[i]) {
            dp[i] = dp[i - 1] + 1;
            ret += dp[i];
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> input{1, 2, 3, 4};
        assert(numberOfAnrithmeticSlices(input) == 3);
    }
    return 0;
}
