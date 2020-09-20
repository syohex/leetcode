#include <cassert>
#include <vector>
#include <cstdio>

int sumOddLengthSubarrays(const std::vector<int> &arr) {
    int ret = 0;

    int limit = static_cast<int>(arr.size());
    for (int i = 1; i <= limit; i += 2) {
        for (int j = 0; j <= limit - i; ++j) {
            for (int k = 0; k < i; ++k) {
                ret += arr[j + k];
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> input{1, 4, 2, 5, 3};
        assert(sumOddLengthSubarrays(input) == 58);
    }
    {
        std::vector<int> input{1, 2};
        assert(sumOddLengthSubarrays(input) == 3);
    }
    {
        std::vector<int> input{10, 11, 12};
        assert(sumOddLengthSubarrays(input) == 66);
    }
    return 0;
}
