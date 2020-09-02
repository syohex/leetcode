#include <cassert>
#include <vector>
#include <map>

bool containsNearbyDuplicate(const std::vector<int> &nums, int k) {
    std::map<int, int> m;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        auto it = m.find(nums[i]);
        if (it == m.end()) {
            m[nums[i]] = i;
            continue;
        }

        int index = it->second;
        if (i - index <= k) {
            return true;
        }

        m[nums[i]] = i;
    }

    return false;
}

int main() {
    assert((containsNearbyDuplicate(std::vector<int>{1, 2, 3, 1}, 3)));
    assert((containsNearbyDuplicate(std::vector<int>{1, 0, 1, 1}, 1)));
    assert((!containsNearbyDuplicate(std::vector<int>{1, 2, 3, 1, 2, 3}, 2)));
    assert((containsNearbyDuplicate(std::vector<int>{99, 99}, 2)));
    return 0;
}
