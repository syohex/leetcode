#include <cassert>
#include <vector>
#include <queue>
#include <map>

std::vector<int> topKFrequent(const std::vector<int> &nums, int k) {
    struct Info {
        explicit Info(int value, int count) : value(value), count(count) {
        }

        int value;
        int count;
    };

    std::map<int, int> m;
    for (int n : nums) {
        ++m[n];
    }

    const auto cmp = [](const Info &a, const Info &b) { return a.count < b.count; };

    std::priority_queue<Info, std::vector<Info>, decltype(cmp)> q(cmp);
    for (const auto &it : m) {
        q.emplace(it.first, it.second);
    }

    std::vector<int> ret;
    for (int i = 0; i < k; ++i) {
        ret.push_back(q.top().value);
        q.pop();
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 1, 1, 2, 2, 3};
        auto ret = topKFrequent(nums, 2);
        assert((ret == std::vector<int>{1, 2}));
    }
    {
        std::vector<int> nums{1};
        auto ret = topKFrequent(nums, 1);
        assert((ret == std::vector<int>{1}));
    }
    return 0;
}
