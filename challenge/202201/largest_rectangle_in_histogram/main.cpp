#include <cassert>
#include <vector>
#include <algorithm>

int largestRectangleArea(const std::vector<int> &heights) {
    std::vector<int> stack;
    stack.push_back(-1);

    int ret = 0;
    int len = heights.size();
    for (int i = 0; i < len; ++i) {
        while (stack.back() != -1 && heights[stack.back()] >= heights[i]) {
            int pos = stack.back();
            stack.pop_back();

            int area = heights[pos] * (i - stack.back() - 1);
            ret = std::max(ret, area);
        }
        stack.push_back(i);
    }

    while (stack.back() != -1) {
        int pos = stack.back();
        stack.pop_back();

        int area = heights[pos] * (len - stack.back() - 1);
        ret = std::max(ret, area);
    }

    return ret;
}

int main() {
    {
        std::vector<int> heights{2, 1, 5, 6, 2, 3};
        assert(largestRectangleArea(heights) == 10);
    }
    {
        std::vector<int> heights{2, 4};
        assert(largestRectangleArea(heights) == 4);
    }
    return 0;
}
