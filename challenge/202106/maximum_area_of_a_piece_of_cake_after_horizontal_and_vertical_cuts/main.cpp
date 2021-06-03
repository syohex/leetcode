#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>

int maxArea(int h, int w, std::vector<int> &horizontalCuts, std::vector<int> &verticalCuts) {
    horizontalCuts.push_back(0);
    horizontalCuts.push_back(h);
    std::sort(horizontalCuts.begin(), horizontalCuts.end());

    verticalCuts.push_back(0);
    verticalCuts.push_back(w);
    std::sort(verticalCuts.begin(), verticalCuts.end());

    long MOD = std::pow(10, 9) + 7;
    long ret = 0;
    for (size_t i = 1; i < horizontalCuts.size(); ++i) {
        long height = horizontalCuts[i] - horizontalCuts[i - 1];
        for (size_t j = 1; j < verticalCuts.size(); ++j) {
            long width = verticalCuts[j] - verticalCuts[j - 1];
            ret = std::max(ret, (width * height) % MOD);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> horizontalCuts{1, 2, 4};
        std::vector<int> verticalCuts{1, 3};
        assert(maxArea(5, 4, horizontalCuts, verticalCuts) == 4);
    }
    {
        std::vector<int> horizontalCuts{3, 1};
        std::vector<int> verticalCuts{1};
        assert(maxArea(5, 4, horizontalCuts, verticalCuts) == 6);
    }
    return 0;
}
