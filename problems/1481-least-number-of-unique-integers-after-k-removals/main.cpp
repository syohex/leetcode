#include <cassert>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>

int findLeastNumOfUniqueInts(const std::vector<int> &arr, int k) {
    std::map<int, int> m;
    for (int a : arr) {
        ++m[a];
    }

    struct Info {
        int num;
        int count;
    };

    auto cmp = [](const Info &a, const Info &b) { return a.count > b.count; };

    std::priority_queue<Info, std::vector<Info>, decltype(cmp)> q(cmp);
    for (const auto &it : m) {
        q.emplace(Info{it.first, it.second});
    }

    while (!q.empty()) {
        auto &info = q.top();
        if (info.count > k) {
            break;
        }

        k -= info.count;
        q.pop();
    }

    return static_cast<int>(q.size());
}

int main() {
    {
        std::vector<int> arr{5, 5, 4};
        assert(findLeastNumOfUniqueInts(arr, 1) == 1);
    }
    {
        std::vector<int> arr{4, 3, 1, 1, 3, 3, 2};
        assert(findLeastNumOfUniqueInts(arr, 3) == 2);
    }
    return 0;
}
