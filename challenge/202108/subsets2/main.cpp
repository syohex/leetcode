#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>
#include <set>

std::vector<std::vector<int>> subsetsWithDup(const std::vector<int> &nums) {
    std::set<std::vector<int>> s;

    std::function<void(size_t pos, std::vector<int> & v)> f;
    f = [&f, &nums, &s](size_t pos, std::vector<int> &v) {
        if (pos == nums.size()) {
            std::sort(v.begin(), v.end());
            s.insert(v);
            return;
        }

        auto tmp = v;
        tmp.push_back(nums[pos]);
        f(pos + 1, tmp);
        f(pos + 1, v);
    };

    std::vector<int> tmp;
    f(0, tmp);
    return std::vector<std::vector<int>>(s.begin(), s.end());
}

void check(const std::vector<std::vector<int>> &a, const std::vector<std::vector<int>> &b) {
    assert(a.size() == b.size());

    std::set<std::vector<int>> sa(a.begin(), a.end());
    std::set<std::vector<int>> sb(b.begin(), b.end());
    assert(sa == sb);
}

int main() {
    {
        std::vector<int> nums{1, 2, 2};
        std::vector<std::vector<int>> expected{
            {}, {1}, {1, 2}, {1, 2, 2}, {2}, {2, 2},
        };
        auto ret = subsetsWithDup(nums);
        check(ret, expected);
    }
    {
        std::vector<int> nums{0};
        std::vector<std::vector<int>> expected{
            {},
            {0},
        };
        auto ret = subsetsWithDup(nums);
        check(ret, expected);
    }
    {
        std::vector<int> nums{4, 4, 4, 1, 4};
        std::vector<std::vector<int>> expected{{},  {1},    {1, 4},    {1, 4, 4},   {1, 4, 4, 4}, {1, 4, 4, 4, 4},
                                               {4}, {4, 4}, {4, 4, 4}, {4, 4, 4, 4}};
        auto ret = subsetsWithDup(nums);
        check(ret, expected);
    }
    return 0;
}
