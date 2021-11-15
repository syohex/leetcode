#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>
#include <map>

std::vector<int> largestDivisibleSubset(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    std::map<size_t, std::vector<int>> cache;
    std::function<std::vector<int>(size_t pos)> f;
    f = [&](size_t pos) -> std::vector<int> {
        if (cache.find(pos) != cache.end()) {
            return cache[pos];
        }

        std::vector<int> ret;
        for (size_t i = 0; i < pos; ++i) {
            if (nums[pos] % nums[i] == 0) {
                auto tmp = f(i);
                if (tmp.size() > ret.size()) {
                    ret = std::move(tmp);
                }
            }
        }

        ret.push_back(nums[pos]);
        cache[pos] = ret;
        return ret;
    };

    std::vector<int> ret;
    for (size_t i = 0; i < nums.size(); ++i) {
        auto tmp = f(i);
        if (tmp.size() > ret.size()) {
            ret = std::move(tmp);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 2, 3};
        std::vector<int> expected{1, 2};
        auto ret = largestDivisibleSubset(nums);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{1, 2, 4, 8};
        std::vector<int> expected{1, 2, 4, 8};
        auto ret = largestDivisibleSubset(nums);
        assert(ret == expected);
    }
    return 0;
}