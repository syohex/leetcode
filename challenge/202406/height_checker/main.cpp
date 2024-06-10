#include <cassert>
#include <vector>
#include <algorithm>

int heightChecker(const std::vector<int> &heights) {
    auto v = heights;
    std::sort(v.begin(), v.end());

    int ret = 0;
    for (std::size_t i = 0; i < v.size(); ++i) {
        if (heights[i] != v[i]) {
            ++ret;
        }
    }
    return ret;
}

int main() {
    {
        std::vector<int> heights{1, 1, 4, 2, 1, 3};
        int ret = heightChecker(heights);
        assert(ret == 3);
    }
    {
        std::vector<int> heights{5, 1, 2, 3, 4};
        int ret = heightChecker(heights);
        assert(ret == 5);
    }
    {
        std::vector<int> heights{1, 2, 3, 4, 5};
        int ret = heightChecker(heights);
        assert(ret == 0);
    }
    return 0;
}
