#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>

std::vector<int> findClosestElements(std::vector<int> &arr, int k, int x) {
    std::sort(arr.begin(), arr.end(), [&x](int a, int b) {
        int abs_a = std::abs(a - x);
        int abs_b = std::abs(b - x);
        if (abs_a == abs_b) {
            return a < b;
        } else {
            return abs_a < abs_b;
        }
    });

    std::vector<int> ret;
    for (int i = 0; i < k; ++i) {
        ret.push_back(arr[i]);
    }

    std::sort(ret.begin(), ret.end());
    return ret;
}

int main() {
    {
        std::vector<int> arr{1, 2, 3, 4, 5};
        std::vector<int> expected{1, 2, 3, 4};
        auto ret = findClosestElements(arr, 4, 3);
        assert(ret == expected);
    }
    {
        std::vector<int> arr{1, 2, 3, 4, 5};
        std::vector<int> expected{1, 2, 3, 4};
        auto ret = findClosestElements(arr, 4, -1);
        assert(ret == expected);
    }
    return 0;
}
