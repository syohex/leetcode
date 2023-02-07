#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>

int totalFruit(const std::vector<int> &fruits) {
    int ret = 0;
    std::map<int, int> m;

    int len = fruits.size();
    for (int left = 0, right = 0; right < len; ++right) {
        m[fruits[right]] += 1;

        if (m.size() > 2) {
            m[fruits[left]] -= 1;
            if (m[fruits[left]] == 0) {
                m.erase(fruits[left]);
            }
            left += 1;
        }

        if (m.size() <= 2) {
            ret = std::max(ret, right - left + 1);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> fruits{1, 2, 1};
        int ret = totalFruit(fruits);
        assert(ret == 3);
    }
    {
        std::vector<int> fruits{0, 1, 2, 2};
        int ret = totalFruit(fruits);
        assert(ret == 3);
    }
    {
        std::vector<int> fruits{1, 2, 3, 2, 2};
        int ret = totalFruit(fruits);
        assert(ret == 4);
    }
    {
        std::vector<int> fruits{1, 0, 1, 4, 1, 4, 1, 2, 3};
        int ret = totalFruit(fruits);
        assert(ret == 5);
    }
    return 0;
}
