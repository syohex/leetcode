#include <cassert>
#include <vector>
#include <functional>
#include <set>
#include <cstdio>

void check(const std::vector<std::vector<int>> &got, const std::vector<std::vector<int>> &expected) {
    assert(got.size() == expected.size());

    std::set<std::vector<int>> a(got.begin(), got.end());
    std::set<std::vector<int>> b(expected.begin(), expected.end());
    assert(a == b);
}

std::vector<std::vector<int>> permute(const std::vector<int> &nums) {
    std::vector<std::vector<int>> ret;
    std::function<void(size_t pos, std::vector<int> & acc, std::vector<bool> & checked)> f;
    f = [&](size_t pos, std::vector<int> &acc, std::vector<bool> &checked) {
        if (pos == nums.size()) {
            ret.push_back(acc);
            return;
        }

        for (size_t i = 0; i < nums.size(); ++i) {
            if (checked[i]) {
                continue;
            }

            checked[i] = true;
            acc[pos] = nums[i];
            f(pos + 1, acc, checked);
            checked[i] = false;
        }
    };

    std::vector<int> acc(nums.size());
    std::vector<bool> checked(nums.size(), false);
    f(0, acc, checked);
    return ret;
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
