#include <cassert>
#include <vector>
#include <algorithm>

int maxArea(const std::vector<int> &height) {
    int left = 0;
    int right = static_cast<int>(height.size() - 1);

    int ret = 0;
    while (left < right) {
        int area = (right - left) * std::min(height[left], height[right]);
        ret = std::max(ret, area);
        if (height[left] > height[right]) {
            --right;
        } else {
            ++left;
        }
    }

    return ret;
}

int main() {
    assert((maxArea(std::vector<int>{1, 8, 6, 2, 5, 4, 8, 3, 7}) == 49));
    assert((maxArea(std::vector<int>{1, 1}) == 1));
    assert((maxArea(std::vector<int>{4, 3, 2, 1, 4}) == 16));
    assert((maxArea(std::vector<int>{1, 2, 1}) == 2));
    return 0;
}
