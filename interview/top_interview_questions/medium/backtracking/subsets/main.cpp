#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>
#include <set>
#include <cstdio>

std::vector<std::vector<int>> subsets(const std::vector<int> &nums) {
    std::vector<std::vector<int>> ret;
    std::set<std::vector<int>> cache;
    std::function<void(size_t pos, std::vector<int> acc)> f;
    f = [&f, &nums, &ret, &cache](size_t pos, std::vector<int> acc) {
        if (pos == nums.size()) {
            if (cache.find(acc) != cache.end()) {
                return;
            }

            ret.push_back(acc);
            cache.insert(acc);
            return;
        }

        f(pos + 1, acc);

        for (size_t i = pos; i < nums.size(); ++i) {
            auto tmp = acc;
            tmp.push_back(nums[i]);
            f(i + 1, tmp);
        }
    };

    f(0, std::vector<int>{});
    return ret;
}

template <typename T>
bool check(const T &got, const T &expected) {
    if (got.size() != expected.size()) {
        return false;
    }

    std::set<std::vector<int>> gs, es;
    for (const auto &v : got) {
        gs.insert(v);
    }
    for (const auto &v : expected) {
        es.insert(v);
    }

    return gs == es;
}

int main() {
    {
        auto ret = subsets(std::vector<int>{1, 2, 3});
        std::vector<std::vector<int>> expected{
            {}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3},
        };
        assert(check(ret, expected));
    }
    {
        auto ret = subsets(std::vector<int>{0});
        std::vector<std::vector<int>> expected{{}, {0}};
        assert(check(ret, expected));
    }
    return 0;
}
