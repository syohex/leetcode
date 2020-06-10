#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>
#include <set>

std::vector<std::vector<int>> threeSum(const std::vector<int> &nums) {
    std::set<int> table;
    for (const auto n : nums) {
        table.insert(n);
    }

    std::function<void(const std::vector<int> &, size_t, std::vector<int> &, size_t)> f;

    std::set<std::vector<int>> s;
    f = [&f, &s, &table](const std::vector<int> &v, size_t index, std::vector<int> &acc, size_t remain) {
        if (index + remain >= v.size()) {
            return;
        }

        {
            acc[remain] = v[index];
            if (remain == 0) {
                if (acc[0] + acc[1] + acc[2] == 0) {
                    auto tmp = acc;
                    std::sort(tmp.begin(), tmp.end());
                    s.insert(tmp);
                }
            } else if (remain == 1) {
                int last = 0 - (acc[1] + acc[2]);
                if (table.find(last) != table.end()) {
                    f(v, index + 1, acc, remain - 1);
                }
            } else {
                f(v, index + 1, acc, remain - 1);
            }
        }

        f(v, index + 1, acc, remain);
    };

    std::vector<int> acc(3, 0);
    f(nums, 0, acc, 2);

    std::vector<std::vector<int>> ret;
    for (const auto &v : s) {
        ret.push_back(v);
    }
    return ret;
}

bool check(const std::vector<std::vector<int>> &got, const std::vector<std::vector<int>> &expected) {
    if (got.size() != expected.size()) {
        return 0;
    }

    std::set<std::vector<int>> g, e;
    for (size_t i = 0; i < got.size(); ++i) {
        g.insert(got[i]);
        e.insert(expected[i]);
    }

    return g == e;
}

int main() {
    {
        std::vector<int> input{-1, 0, 1, 2, -1, 4};
        std::vector<std::vector<int>> expected{
            {-1, 0, 1},
            {-1, -1, 2},
        };
        auto ret = threeSum(input);
        assert(check(ret, expected));
    }
    {
        std::vector<int> input{3, 0, -2, -1, 1, 2};
        std::vector<std::vector<int>> expected{
            {-2, -1, 3},
            {-2, 0, 2},
            {-1, 0, 1},
        };
        auto ret = threeSum(input);
        assert(check(ret, expected));
    }
    return 0;
}
