#include <cassert>
#include <vector>
#include <queue>
#include <cstdio>

std::vector<int> mostCompetitive(const std::vector<int> &nums, int k) {
    std::deque<int> q;
    int rest = nums.size() - k;

    for (int n : nums) {
        while (!q.empty() && q.back() > n && rest > 0) {
            q.pop_back();
            --rest;
        }

        q.push_back(n);
    }

    std::vector<int> ret(k);
    for (int i = 0; i < k; ++i) {
        ret[i] = q.front();
        q.pop_front();
    }

    return ret;
}

int main() {
    {
        std::vector<int> input{3, 5, 2, 6};
        std::vector<int> expected{2, 6};
        auto ret = mostCompetitive(input, 2);
        assert(ret == expected);
    }
    {
        std::vector<int> input{2, 4, 3, 3, 5, 4, 9, 6};
        std::vector<int> expected{2, 3, 3, 4};
        auto ret = mostCompetitive(input, 4);
        assert(ret == expected);
    }
    return 0;
}
