#include <cassert>
#include <vector>
#include <algorithm>
#include <map>

std::vector<int> findOriginalArray(std::vector<int> &changed) {
    std::sort(changed.begin(), changed.end());

    std::map<int, int> m;
    for (int n : changed) {
        ++m[n];
    }

    std::vector<int> ret;
    for (int n : changed) {
        if (m[n] == 0) {
            continue;
        }

        --m[n];

        int doubled = n * 2;
        const auto it = m.find(doubled);
        if (it == m.end()) {
            return {};
        }

        if (n == doubled) {
            if (it->second == 0) {
                return {};
            }
        } else {
            if (it->second == 0) {
                continue;
            }
        }

        --it->second;
        ret.push_back(n);
    }

    if (ret.size() * 2 != changed.size()) {
        return {};
    }

    return ret;
}

int main() {
    {
        std::vector<int> changed{1, 3, 4, 2, 6, 8};
        std::vector<int> expected{1, 3, 4};

        auto ret = findOriginalArray(changed);
        assert(ret == expected);
    }
    {
        std::vector<int> changed{6, 3, 0, 1};
        auto ret = findOriginalArray(changed);
        assert(ret.empty());
    }
    {
        std::vector<int> changed{1};
        auto ret = findOriginalArray(changed);
        assert(ret.empty());
    }
    {
        std::vector<int> changed{0};
        auto ret = findOriginalArray(changed);
        assert(ret.empty());
    }
    {
        std::vector<int> changed{0, 0};
        std::vector<int> expected{0};
        auto ret = findOriginalArray(changed);
        assert(ret == expected);
    }
    {
        std::vector<int> changed{0, 0, 0};
        auto ret = findOriginalArray(changed);
        assert(ret.empty());
    }
    {
        std::vector<int> changed{5, 7, 2, 10, 4, 2, 7, 14};
        auto ret = findOriginalArray(changed);
        assert(ret.empty());
    }
    return 0;
}