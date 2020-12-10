#include <cassert>
#include <vector>
#include <functional>
#include <set>
#include <cstdio>

std::vector<std::vector<int>> subsets(const std::vector<int> &nums) {
    std::vector<std::vector<int>> ret;
    std::function<void(size_t pos, const std::vector<int> &acc)> f;
    f = [&f, &ret, &nums](size_t pos, const std::vector<int> &acc) {
        if (pos == nums.size()) {
            ret.push_back(acc);
            return;
        }

        f(pos + 1, acc);

        auto tmp = acc;
        tmp.push_back(nums[pos]);
        f(pos + 1, tmp);
    };

    f(0, std::vector<int>{});
    return ret;
}

void check(const std::vector<std::vector<int>> &got, const std::vector<std::vector<int>> &expected) {
    std::set<std::vector<int>> gs, es;
    for (const auto i : got) {
        gs.insert(i);
    }
    for (const auto i : expected) {
        es.insert(i);
    }

    assert(gs == es);
}

int main() {
    {
        std::vector<int> nums{1, 2, 3};
        std::vector<std::vector<int>> expected{
            {}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3},
        };
        auto ret = subsets(nums);
        check(ret, expected);
    }
    {
        std::vector<int> nums{
            0,
        };
        std::vector<std::vector<int>> expected{
            {},
            {0},
        };
        auto ret = subsets(nums);
        check(ret, expected);
    }

    return 0;
}
