#include <cassert>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

std::vector<std::vector<int>> minimumAbsDifference(std::vector<int> &arr) {
    std::sort(arr.begin(), arr.end());

    std::map<int, std::vector<std::vector<int>>> m;
    int len = arr.size();
    for (int i = 0; i < len - 1; ++i) {
        int diff = arr[i + 1] - arr[i];
        m[diff].push_back({arr[i], arr[i + 1]});
    }

    return m.begin()->second;
}

int main() {
    {
        std::vector<int> arr{4, 2, 1, 3};
        std::vector<std::vector<int>> expected{{1, 2}, {2, 3}, {3, 4}};
        auto ret = minimumAbsDifference(arr);
        assert(ret == expected);
    }
    {
        std::vector<int> arr{1, 3, 6, 10, 15};
        std::vector<std::vector<int>> expected{{1, 3}};
        auto ret = minimumAbsDifference(arr);
        assert(ret == expected);
    }
    {
        std::vector<int> arr{3, 8, -10, 23, 19, -4, -14, 27};
        std::vector<std::vector<int>> expected{{-14, -10}, {19, 23}, {23, 27}};
        auto ret = minimumAbsDifference(arr);
        assert(ret == expected);
    }
    return 0;
}