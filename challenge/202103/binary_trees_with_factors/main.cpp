#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

int numFactoredBinaryTree(std::vector<int> &arr) {
    std::sort(arr.begin(), arr.end());

    std::vector<long> dp(arr.size(), 1);
    std::map<int, size_t> s;
    for (size_t i = 0; i < arr.size(); ++i) {
        s[arr[i]] = i;
    }

    const int modulo = std::pow(10, 9) + 7;
    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (arr[i] % arr[j] == 0) {
                int other = arr[i] / arr[j];
                if (s.find(other) != s.end()) {
                    size_t other_index = s[other];
                    dp[i] = (dp[i] + (dp[j] * dp[other_index])) % modulo;
                }
            }
        }
    }

    long ret = 0;
    for (auto d : dp) {
        ret += (d % modulo);
    }

    return static_cast<int>(ret % modulo);
}

int main() {
    {
        std::vector<int> arr{2, 4};
        assert(numFactoredBinaryTree(arr) == 3);
    }
    {
        std::vector<int> arr{2, 4, 5, 10};
        assert(numFactoredBinaryTree(arr) == 7);
    }
    return 0;
}
