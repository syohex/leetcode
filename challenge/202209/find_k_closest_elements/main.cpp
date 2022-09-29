#include <cassert>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

std::vector<int> findClosestElements(std::vector<int> &arr, int k, int x) {
    const auto cmp = [&x](int a, int b) -> bool {
        int a_abs = std::abs(a - x);
        int b_abs = std::abs(b - x);
        if (a_abs == b_abs) {
            return a < b;
        }

        return a_abs < b_abs;
    };

    std::sort(arr.begin(), arr.end(), cmp);

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
