#include <cassert>
#include <vector>
#include <cstdio>
#include <map>
#include <climits>
#include <algorithm>

std::vector<std::vector<int>> minimumAbsDifference(const std::vector<int> &arr) {
    std::map<int, std::vector<std::vector<int>>> m;

    int min = INT_MAX;
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = i + 1; j < arr.size(); ++j) {
            int diff = arr[j] > arr[i] ? arr[j] - arr[i] : arr[i] - arr[j];
            if (diff > min) {
                continue;
            }

            min = diff;
            if (arr[i] <= arr[j]) {
                m[diff].push_back(std::vector<int>{arr[i], arr[j]});
            } else {
                m[diff].push_back(std::vector<int>{arr[j], arr[i]});
            }
        }
    }

    auto &ret = m[min];
    std::sort(ret.begin(), ret.end(), [](const std::vector<int> &a, const std::vector<int> &b) -> bool { return a[0] < b[0]; });
    return ret;
}

int main() {
    {
        std::vector<int> input{4, 2, 1, 3};
        std::vector<std::vector<int>> expected{
            {1, 2},
            {2, 3},
            {3, 4},
        };
        auto got = minimumAbsDifference(input);
        assert(got == expected);
    }
    {
        std::vector<int> input{1, 3, 6, 10, 15};
        std::vector<std::vector<int>> expected{
            {1, 3},
        };
        auto got = minimumAbsDifference(input);
        assert(got == expected);
    }
    {
        std::vector<int> input{3, 8, -10, 23, 19, -4, -14, 27};
        std::vector<std::vector<int>> expected{
            {-14, -10},
            {19, 23},
            {23, 27},
        };
        auto got = minimumAbsDifference(input);
        assert(got == expected);
    }
    return 0;
}
