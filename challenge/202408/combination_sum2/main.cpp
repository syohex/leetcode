#include <cassert>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>

std::vector<std::vector<int>> combinationSum2(std::vector<int> candidates, int target) {
    std::set<std::vector<int>> s;
    int len = candidates.size();

    std::function<void(int pos, int sum, std::vector<int> &acc)> f;
    f = [&](int pos, int sum, std::vector<int> &acc) {
        if (sum == target) {
            s.insert(acc);
            return;
        }

        for (int i = pos; i < len; ++i) {
            if (sum + candidates[i] > target) {
                break;
            }

            acc.push_back(candidates[i]);
            f(i + 1, sum + candidates[i], acc);
            acc.pop_back();
        }
    };

    std::sort(candidates.begin(), candidates.end());
    std::vector<int> acc;
    f(0, 0, acc);

    return std::vector(s.begin(), s.end());
}

int main() {
    {
        std::vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
        std::set<std::vector<int>> expected{{1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6}};
        auto ret = combinationSum2(candidates, 8);
        assert(std::set<std::vector<int>>(ret.begin(), ret.end()) == expected);
    }
    {
        std::vector<int> candidates{2, 5, 2, 1, 2};
        std::set<std::vector<int>> expected{{1, 2, 2}, {5}};
        auto ret = combinationSum2(candidates, 5);
        assert(std::set<std::vector<int>>(ret.begin(), ret.end()) == expected);
    }
    return 0;
}