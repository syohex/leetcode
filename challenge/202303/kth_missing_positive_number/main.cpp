#include <cassert>
#include <vector>
#include <set>

int findKthPositive(const std::vector<int> &arr, int k) {
    std::set<int> s(arr.begin(), arr.end());

    int missing = 0;
    for (int i = 1;; ++i) {
        if (s.find(i) == s.end()) {
            ++missing;
            if (missing == k) {
                return i;
            }
        }
    }

    return -1;
}

int main() {
    {
        std::vector<int> arr{2, 3, 4, 7, 11};
        int ret = findKthPositive(arr, 5);
        assert(ret == 9);
    }
    {
        std::vector<int> arr{1, 2, 3, 4};
        int ret = findKthPositive(arr, 2);
        assert(ret == 6);
    }
    return 0;
}
