#include <cassert>
#include <vector>
#include <map>

bool isNStraightHand(const std::vector<int> &hand, int groupSize) {
    if (hand.size() % groupSize != 0) {
        return false;
    }

    std::map<int, int> m;
    for (int h : hand) {
        ++m[h];
    }

    while (!m.empty()) {
        int minimum_key = m.begin()->first;

        for (int i = 0; i < groupSize; ++i) {
            int key = minimum_key + i;
            if (m.find(key) == m.end()) {
                return false;
            }

            --m[key];
            if (m[key] == 0) {
                m.erase(key);
            }
        }
    }

    return true;
}

int main() {
    {
        std::vector<int> nums{1, 2, 3, 6, 2, 3, 4, 7, 8};
        assert(isNStraightHand(nums, 3));
    }
    {
        std::vector<int> nums{1, 2, 3, 4, 5};
        assert(!isNStraightHand(nums, 4));
    }
    return 0;
}
