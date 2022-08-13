#include <cassert>
#include <vector>
#include <map>

std::vector<std::vector<int>> mergeSimilarItems(const std::vector<std::vector<int>> &items1,
                                                const std::vector<std::vector<int>> &items2) {
    std::map<int, int> m;
    for (const auto &v : items1) {
        m[v[0]] += v[1];
    }
    for (const auto &v : items2) {
        m[v[0]] += v[1];
    }

    std::vector<std::vector<int>> ret;
    for (const auto &it : m) {
        ret.push_back({it.first, it.second});
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<int>> items1{{1, 1}, {4, 5}, {3, 8}};
        std::vector<std::vector<int>> items2{{3, 1}, {1, 5}};
        std::vector<std::vector<int>> expected{{1, 6}, {3, 9}, {4, 5}};
        auto ret = mergeSimilarItems(items1, items2);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> items1{{1, 3}, {2, 2}};
        std::vector<std::vector<int>> items2{{7, 1}, {2, 2}, {1, 4}};
        std::vector<std::vector<int>> expected{{1, 7}, {2, 4}, {7, 1}};
        auto ret = mergeSimilarItems(items1, items2);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<int>> items1{{1, 1}, {3, 2}, {2, 3}};
        std::vector<std::vector<int>> items2{{2, 1}, {3, 2}, {1, 3}};
        std::vector<std::vector<int>> expected{{1, 4}, {2, 4}, {3, 4}};
        auto ret = mergeSimilarItems(items1, items2);
        assert(ret == expected);
    }
    return 0;
}
