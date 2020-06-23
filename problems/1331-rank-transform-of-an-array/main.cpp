#include <cassert>
#include <vector>
#include <algorithm>
#include <map>

std::vector<int> arrayRankTransform(const std::vector<int> &arr) {
    if (arr.empty()) {
        return std::vector<int>{};
    }
    if (arr.size() == 1) {
        return std::vector<int>{1};
    }

    std::vector<int> tmp(arr);
    std::sort(tmp.begin(), tmp.end());

    std::map<int, size_t> m{
        {tmp[0], 1},
    };

    size_t j = 2;
    for (size_t i = 1; i < tmp.size(); ++i) {
        if (tmp[i - 1] != tmp[i]) {
            m[tmp[i]] = j++;
        }
    }

    std::vector<int> ret(arr.size());
    for (size_t i = 0; i < arr.size(); ++i) {
        ret[i] = m[arr[i]];
    }
    return ret;
}

int main() {
    {
        std::vector<int> input{40, 10, 20, 30};
        assert((arrayRankTransform(input) == std::vector<int>{4, 1, 2, 3}));
    }
    {
        std::vector<int> input{100, 100, 100};
        assert((arrayRankTransform(input) == std::vector<int>{1, 1, 1}));
    }
    {
        std::vector<int> input{37, 12, 28, 9, 100, 56, 80, 5, 12};
        assert((arrayRankTransform(input) == std::vector<int>{5, 3, 4, 2, 8, 6, 7, 1, 3}));
    }
    return 0;
}
