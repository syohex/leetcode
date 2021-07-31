#include <cassert>
#include <vector>
#include <algorithm>

int trap(const std::vector<int> &height) {
    if (height.empty()) {
        return 0;
    }

    int len = height.size();
    std::vector<int> lefts(len, 0);
    std::vector<int> rights(len, 0);

    lefts[0] = height[0];
    rights[len - 1] = height[len - 1];

    for (int i = 1; i < len; ++i) {
        lefts[i] = std::max(height[i], lefts[i - 1]);
    }

    for (int i = len - 2; i >= 0; --i) {
        rights[i] = std::max(height[i], rights[i + 1]);
    }

    int ret = 0;
    for (int i = 1; i < len - 1; ++i) {
        ret += std::min(lefts[i], rights[i]) - height[i];
    }

    return ret;
}

int main() {
    {
        std::vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        assert(trap(height) == 6);
    }
    {
        std::vector<int> height{4, 2, 0, 3, 2, 5};
        assert(trap(height) == 9);
    }
    return 0;
}