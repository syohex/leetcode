#include <cassert>
#include <algorithm>
#include <vector>

int heightChecker(const std::vector<int> &heights) {
    std::vector<int> tmp(heights);
    std::sort(tmp.begin(), tmp.end());

    int ret = 0;
    for (size_t i = 0; i < heights.size(); ++i) {
        if (tmp[i] != heights[i]) {
            ++ret;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> heights{1, 1, 4, 2, 1, 3};
        assert(heightChecker(heights) == 3);
    }
    {
        std::vector<int> heights{5, 1, 2, 3, 4};
        assert(heightChecker(heights) == 5);
    }
    {
        std::vector<int> heights{1, 2, 3, 4, 5};
        assert(heightChecker(heights) == 0);
    }
    return 0;
}
