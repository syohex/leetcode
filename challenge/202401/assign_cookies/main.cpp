#include <cassert>
#include <vector>
#include <algorithm>

int findContentChildren(std::vector<int> &g, std::vector<int> &s) {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());

    int ret = 0;
    size_t i = 0;
    for (int cookie : s) {
        if (cookie >= g[i]) {
            ret += 1;
            i += 1;
        }

        if (i >= g.size()) {
            break;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> g{1, 2, 3};
        std::vector<int> s{1, 1};
        int ret = findContentChildren(g, s);
        assert(ret == 1);
    }
    {
        std::vector<int> g{1, 2};
        std::vector<int> s{1, 2, 3};
        int ret = findContentChildren(g, s);
        assert(ret == 2);
    }
    return 0;
}
