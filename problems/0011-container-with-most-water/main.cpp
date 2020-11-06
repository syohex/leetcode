#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

int maxArea(const std::vector<int> &height) {
    int low = 0;
    int high = static_cast<int>(height.size() - 1);

    int max = 0;
    while (low < high) {
        int area = (high - low) * std::min(height[low], height[high]);
        max = std::max(max, area);
        if (height[low] > height[high]) {
            --high;
        } else {
            ++low;
        }
    }

    return max;
}

int main() {
    {
        std::vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
        assert(maxArea(height) == 49);
    }
    {
        std::vector<int> height{1, 1};
        assert(maxArea(height) == 1);
    }
    {
        std::vector<int> height{4, 3, 2, 1, 4};
        assert(maxArea(height) == 16);
    }
    {
        std::vector<int> height{1, 2, 1};
        assert(maxArea(height) == 2);
    }
    return 0;
}
