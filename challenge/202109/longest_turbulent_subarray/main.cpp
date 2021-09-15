#include <cassert>
#include <vector>
#include <algorithm>

int maxTurbulenceSize(const std::vector<int> &arr) {
    const auto cmp = [](int a, int b) -> int {
        if (a == b) {
            return 0;
        }

        return a > b ? 1 : -1;
    };

    int len = arr.size();
    int ret = 1;
    int start = 0;
    for (int i = 1; i < len; ++i) {
        int tmp = cmp(arr[i - 1], arr[i]);
        if (tmp == 0) {
            start = i;
        } else if (i == len - 1 || tmp * cmp(arr[i], arr[i + 1]) != -1) {
            ret = std::max(ret, i - start + 1);
            start = i;
        }
    }
    return ret;
}

int main() {
    {
        std::vector<int> arr{9, 4, 2, 10, 7, 8, 8, 1, 9};
        assert(maxTurbulenceSize(arr) == 5);
    }
    {
        std::vector<int> arr{4, 8, 12, 16};
        assert(maxTurbulenceSize(arr) == 2);
    }
    {
        std::vector<int> arr{100};
        assert(maxTurbulenceSize(arr) == 1);
    }
    return 0;
}