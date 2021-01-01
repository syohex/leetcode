#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>
#include <set>
#include <cstdio>

std::vector<std::vector<int>> permute(const std::vector<int> &nums) {
    std::vector<std::vector<int>> ret;
    std::function<void(std::vector<int> acc)> f;
    f = [&f, &ret, &nums](std::vector<int> acc) {
        if (acc.size() == nums.size()) {
            ret.push_back(acc);
            return;
        }

        for (int num : nums) {
            auto it = std::find(acc.begin(), acc.end(), num);
            if (it == acc.end()) {
                auto tmp = acc;
                tmp.push_back(num);
                f(tmp);
            }
        }
    };

    f(std::vector<int>{});
    return ret;
}

template <typename T>
bool check(const T &got, const T &expected) {
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
        std::vector<int> nums{1, 2, 3};
        std::vector<std::vector<int>> expected{
            {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1},
        };
        auto ret = permute(nums);
        assert(check(ret, expected));
    }
    {
        std::vector<int> nums{0, 1};
        std::vector<std::vector<int>> expected{
            {0, 1},
            {1, 0},
        };
        auto ret = permute(nums);
        assert(check(ret, expected));
    }
    {
        std::vector<int> nums{1};
        std::vector<std::vector<int>> expected{
            {1},
        };
        auto ret = permute(nums);
        assert(check(ret, expected));
    }
    return 0;
}
