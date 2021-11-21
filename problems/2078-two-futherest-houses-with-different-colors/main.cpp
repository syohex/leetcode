#include <cassert>
#include <vector>
#include <cmath>
#include <algorithm>

int maxDistance(const std::vector<int> &colors) {
    int ret = 0;
    int len = colors.size();
    for (int i = 0; i < len; ++i) {
        int dist = 0;
        for (int j = i + 1; j < len; ++j) {
            if (colors[i] != colors[j]) {
                dist = j - i;
            }
        }

        ret = std::max(ret, dist);
    }

    return ret;
}

int main() {
    {
        std::vector<int> colors{1, 1, 1, 6, 1, 1, 1};
        assert(maxDistance(colors) == 3);
    }
    {
        std::vector<int> colors{1, 8, 3, 8, 3};
        assert(maxDistance(colors) == 4);
    }
    {
        std::vector<int> colors{0, 1};
        assert(maxDistance(colors) == 1);
    }
    return 0;
}