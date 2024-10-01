#include <cassert>
#include <vector>
#include <unordered_map>

bool canArrange(const std::vector<int> &arr, int k) {
    std::unordered_map<int, int> m;
    for (int n : arr) {
        int mod = (n % k + k) % k;
        ++m[mod];
    }

    if (m[0] % 2 != 0) {
        return false;
    }

    int len = k / 2;
    for (int i = 1; i <= len; ++i) {
        if (m[i] != m[k - i]) {
            return false;
        }
    }

    return true;
}

int main() {
    {
        std::vector<int> arr{1, 2, 3, 4, 5, 10, 6, 7, 8, 9};
        assert(canArrange(arr, 5));
    }
    {
        std::vector<int> arr{1, 2, 3, 4, 5, 6};
        assert(canArrange(arr, 7));
    }
    {
        std::vector<int> arr{1, 2, 3, 4, 5, 6};
        assert(!canArrange(arr, 10));
    }
    return 0;
}