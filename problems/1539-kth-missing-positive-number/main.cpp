#include <cassert>
#include <vector>
#include <set>
#include <cstdio>

int findKthPositive(const std::vector<int> &arr, int k) {
    std::set<int> s;
    for (const auto a : arr) {
        s.insert(a);
    }

    int miss = 0;
    for (int i = 1;; ++i) {
        if (s.find(i) == s.end()) {
            ++miss;
            if (miss == k) {
                return i;
            }
        }
    }

    return -1;
}

int main() {
    {
        std::vector<int> input{2, 3, 4, 7, 11};
        assert(findKthPositive(input, 5) == 9);
    }
    {
        std::vector<int> input{1, 2, 3, 4};
        assert(findKthPositive(input, 2) == 6);
    }
    return 0;
}
