#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <functional>

std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
    std::vector<std::vector<int>> ret;
    std::function<void(size_t limit, size_t pos, std::vector<int> & v, std::map<int, int> & m)> f;
    f = [&f, &ret](size_t limit, size_t pos, std::vector<int> &v, std::map<int, int> &m) {
        if (limit == pos) {
            ret.push_back(std::move(v));
            return;
        }

        for (const auto &it : m) {
            if (it.second != 0) {
                auto m2 = m;
                --m2[it.first];
                auto v2 = v;
                v2.push_back(it.first);
                f(limit, pos + 1, v2, m2);
            }
        }
    };

    std::map<int, int> m;
    for (const auto i : nums) {
        ++m[i];
    }

    std::vector<int> init;
    f(nums.size(), 0, init, m);
    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 1, 2};
        auto ret = permuteUnique(nums);

        std::set<std::vector<int>> s;
        for (const auto &v : ret) {
            s.insert(v);
        }
        assert(s.size() == 3);

        std::vector<std::vector<int>> expected{
            {1, 1, 2},
            {1, 2, 1},
            {2, 1, 1},
        };
        for (const auto &v : expected) {
            assert(s.find(v) != s.end());
        }
    }
    {
        std::vector<int> nums{1, 2, 3};
        auto ret = permuteUnique(nums);

        std::set<std::vector<int>> s;
        for (const auto &v : ret) {
            s.insert(v);
        }
        assert(s.size() == 6);

        std::vector<std::vector<int>> expected{
            {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1},
        };
        for (const auto &v : expected) {
            assert(s.find(v) != s.end());
        }
    }
    return 0;
}
