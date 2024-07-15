#include <cassert>
#include <vector>
#include <cstdio>

int numberOfAlternatingGroups(const std::vector<int> &colors) {
    int ret = 0;
    int len = colors.size();

    for (int i = 0; i < len; ++i) {
        int left = (i + len - 1) % len;
        int right = (i + 1) % len;

        if (colors[left] != colors[i] && colors[i] != colors[right]) {
            ++ret;
        }
    }
    return ret;
}

int main() {
    {
        std::vector<int> colors{1, 1, 1};
        int ret = numberOfAlternatingGroups(colors);
        assert(ret == 0);
    }
    {
        std::vector<int> colors{0, 1, 0, 0, 1};
        int ret = numberOfAlternatingGroups(colors);
        assert(ret == 3);
    }
    return 0;
}
