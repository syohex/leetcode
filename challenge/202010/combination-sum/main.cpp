#include <cassert>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>

std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
    std::sort(candidates.begin(), candidates.end());

    std::vector<std::vector<int>> ret;
    if (candidates[0] > target) {
        return ret;
    }

    std::function<void(size_t index, int sum, const std::vector<int> &v)> f;
    f = [&f, &candidates, &target, &ret](size_t index, int sum, const std::vector<int> &v) {
        int n = candidates[index];
        if (n + sum > target) {
            return;
        }

        std::vector<int> vv = v;
        vv.push_back(n);
        if (sum + n == target) {
            ret.push_back(vv);
        }

        f(index, sum + n, vv);
        if (index < candidates.size() - 1) {
            f(index + 1, sum, v);
        }
    };

    f(0, 0, std::vector<int>{});
    return ret;
}

int main() {
    {
        std::vector<int> input{2, 3, 6, 7};
        std::vector<std::vector<int>> expected{
            {2, 2, 3},
            {7},
        };
        const auto ret = combinationSum(input, 7);
        assert(ret == expected);
    }
    {
        std::vector<int> input{2, 3, 5};
        std::vector<std::vector<int>> expected{
            {2, 2, 2, 2},
            {2, 3, 3},
            {3, 5},
        };
        const auto ret = combinationSum(input, 8);
        assert(ret == expected);
    }
    {
        std::vector<int> input{1};
        std::vector<std::vector<int>> expected{
            {1},
        };
        const auto ret = combinationSum(input, 1);
        assert(ret == expected);
    }
    {
        std::vector<int> input{2};
        const auto ret = combinationSum(input, 1);
        assert(ret.empty());
    }
    {
        std::vector<int> input{1};
        std::vector<std::vector<int>> expected{
            {1, 1},
        };
        const auto ret = combinationSum(input, 2);
        assert(ret == expected);
    }
    return 0;
}
