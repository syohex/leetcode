#include <cassert>
#include <vector>
#include <map>

int majorityElement(const std::vector<int> &nums) {
    std::map<int, int> m;
    for (const auto n : nums) {
        ++m[n];
    }

    int limit = nums.size() / 2;
    for (const auto &it : m) {
        if (it.second > limit) {
            return it.first;
        }
    }

    return 0;
}

int main() {
    assert(majorityElement(std::vector<int>{3, 2, 3}) == 3);
    assert(majorityElement(std::vector<int>{2, 2, 1, 1, 1, 2, 2}) == 2);
    return 0;
}