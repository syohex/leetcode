#include <cassert>
#include <vector>
#include <functional>
#include <set>
#include <cstdio>

std::vector<std::vector<int>> permute(const std::vector<int> &nums) {
    std::vector<std::vector<int>> ret;

    std::function<void(size_t pos, const std::vector<int> &acc)> f;
    f = [&f, &nums, &ret](size_t pos, const std::vector<int> &acc) {
        if (pos == nums.size()) {
            ret.push_back(acc);
            return;
        }

        std::set<int> s;
        for (const auto i : acc) {
            s.insert(i);
        }

        for (size_t i = 0; i < nums.size(); ++i) {
            if (s.find(nums[i]) == s.end()) {
                auto tmp = acc;
                tmp.push_back(nums[i]);
                f(pos + 1, tmp);
            }
        }
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
            {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1},
        };
        auto ret = permute(nums);
        check(ret, expected);
    }
    {
        std::vector<int> nums{0, 1};
        std::vector<std::vector<int>> expected{
            {0, 1},
            {1, 0},
        };
        auto ret = permute(nums);
        check(ret, expected);
    }
    {

        std::vector<int> nums{1};
        std::vector<std::vector<int>> expected{
            {1},
        };
        auto ret = permute(nums);
        check(ret, expected);
    }

    return 0;
}
