#include <cassert>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>

std::vector<int> answerQueries(std::vector<int> &nums, const std::vector<int> &queries) {
    std::sort(nums.begin(), nums.end());

    std::vector<int> acc(nums.size(), 0);

    int sum = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        acc[i] = sum + nums[i];
        sum += nums[i];
    }

    std::vector<int> ret(queries.size(), 0);
    for (size_t i = 0; i < queries.size(); ++i) {
        for (size_t j = 0; j < nums.size(); ++j) {
            if (acc[j] <= queries[i]) {
                ret[i] = j + 1;
            } else {
                break;
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{4, 5, 2, 1};
        std::vector<int> queries{3, 10, 21};
        std::vector<int> expected{2, 3, 4};

        auto ret = answerQueries(nums, queries);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{2, 3, 4, 5};
        std::vector<int> queries{1};
        std::vector<int> expected{0};

        auto ret = answerQueries(nums, queries);
        assert(ret == expected);
    }
    return 0;
}
