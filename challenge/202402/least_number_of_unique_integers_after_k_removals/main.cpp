#include <cassert>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>

int findLeastNumOfUniqueInts(const std::vector<int> &arr, int k) {
    std::map<int, int> m;
    for (int n : arr) {
        ++m[n];
    }

    std::vector<std::pair<int, int>> q;
    for (const auto &[k, v] : m) {
        q.push_back({k, v});
    }

    std::sort(q.begin(), q.end(), [](const auto &a, const auto &b) { return a.second > b.second; });

    while (!q.empty()) {
        int count = q.back().second;
        if (count > k) {
            break;
        }

        q.pop_back();
        k -= count;
    }

    return q.size();
}

int main() {
    {
        std::vector<int> arr{5, 5, 4};
        int ret = findLeastNumOfUniqueInts(arr, 1);
        assert(ret == 1);
    }
    {
        std::vector<int> arr{4, 3, 1, 1, 3, 3, 2};
        int ret = findLeastNumOfUniqueInts(arr, 3);
        assert(ret == 2);
    }
    return 0;
}
