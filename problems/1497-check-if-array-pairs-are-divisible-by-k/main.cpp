#include <cassert>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>

bool canArraynge(std::vector<int> &arr, int k) {
    std::map<int, int> m;
    for (int a : arr) {
        int mod = a % k;
        // C++ negative number % num returns negative number so it converts into positive number
        if (mod < 0) {
            mod += k;
        }
        ++m[mod];
    }

    if (m[0] % 2 != 0) {
        return false;
    }

    for (int i = 1; i <= k / 2; ++i) {
        if (m[i] != m[k - i]) {
            return false;
        }
    }

    return true;
}

int main() {
    {
        std::vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        assert(canArraynge(arr, 5));
    }
    {
        std::vector<int> arr{1, 2, 3, 4, 5, 6};
        assert(canArraynge(arr, 7));
    }
    {
        std::vector<int> arr{1, 2, 3, 4, 5, 6};
        assert(!canArraynge(arr, 10));
    }
    {
        std::vector<int> arr{-10, 10};
        assert(canArraynge(arr, 2));
    }
    {
        std::vector<int> arr{-1, 1, -2, 2, -3, 3, -4, 4};
        assert(canArraynge(arr, 3));
    }
    {
        std::vector<int> arr{-1, -1, -1, -1, 2, 2, -2, -2};
        assert(!canArraynge(arr, 3));
    }
    return 0;
}
