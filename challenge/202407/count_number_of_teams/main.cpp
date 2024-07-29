#include <cassert>
#include <vector>
#include <functional>
#include <map>
#include <cstdio>

int numTeams(const std::vector<int> &rating) {
    std::function<int(std::size_t i, int count, std::map<std::pair<int, int>, int> &cache)> f;
    f = [&](std::size_t i, int count, std::map<std::pair<int, int>, int> &cache) -> int {
        if (count == 3) {
            return 1;
        }

        if (i >= rating.size()) {
            return 0;
        }

        std::pair<int, int> key{i, count};
        if (cache.find(key) != cache.end()) {
            return cache[key];
        }

        int ret = 0;
        for (std::size_t j = i + 1; j < rating.size(); ++j) {
            if (rating[i] < rating[j]) {
                ret += f(j, count + 1, cache);
            }
        }

        cache[key] = ret;
        return ret;
    };

    std::function<int(std::size_t i, int count, std::map<std::pair<int, int>, int> &cache)> g;
    g = [&](std::size_t i, int count, std::map<std::pair<int, int>, int> &cache) -> int {
        if (count == 3) {
            return 1;
        }

        if (i >= rating.size()) {
            return 0;
        }

        std::pair<int, int> key{i, count};
        if (cache.find(key) != cache.end()) {
            return cache[key];
        }

        int ret = 0;
        for (std::size_t j = i + 1; j < rating.size(); ++j) {
            if (rating[i] > rating[j]) {
                ret += g(j, count + 1, cache);
            }
        }

        cache[key] = ret;
        return ret;
    };

    std::map<std::pair<int, int>, int> cache1, cache2;
    int ret = 0;
    for (std::size_t i = 0; i < rating.size(); ++i) {
        ret += f(i, 1, cache1) + g(i, 1, cache2);
    }
    return ret;
}

int main() {
    {
        std::vector<int> nums{2, 5, 3, 4, 1};
        int ret = numTeams(nums);
        assert(ret == 3);
    }
    {
        std::vector<int> nums{2, 1, 3};
        int ret = numTeams(nums);
        assert(ret == 0);
    }
    {
        std::vector<int> nums{1, 2, 3, 4};
        int ret = numTeams(nums);
        assert(ret == 4);
    }
    return 0;
}