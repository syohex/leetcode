#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdint>

std::vector<int> successfulPairs(const std::vector<int> &spells, std::vector<int> &potions, int success) {
    std::sort(potions.begin(), potions.end());

    std::vector<int> ret;
    for (int64_t spell : spells) {
        int left = 0;
        int right = potions.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int64_t p = spell * potions[mid];
            if (p < success) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        ret.push_back(potions.size() - left);
    }

    return ret;
}

int main() {
    {
        std::vector<int> spells{5, 1, 3};
        std::vector<int> potions{1, 2, 3, 4, 5};
        std::vector<int> expected{4, 0, 3};
        int success = 7;
        auto ret = successfulPairs(spells, potions, success);
        assert(ret == expected);
    }
    {
        std::vector<int> spells{3, 1, 2};
        std::vector<int> potions{8, 5, 8};
        std::vector<int> expected{2, 0, 2};
        int success = 16;
        auto ret = successfulPairs(spells, potions, success);
        assert(ret == expected);
    }
    return 0;
}
