#include <cassert>
#include <vector>
#include <map>

int singleNumber(const std::vector<int> &nums) {
    std::map<int, int> m;
    for (const auto num : nums) {
        ++m[num];
    }
    for (const auto &it : m) {
        if (it.second == 1) {
            return it.first;
        }
    }

    return -1;
}

int main() {
    assert(singleNumber(std::vector<int>{2, 2, 1}) == 1);
    assert(singleNumber(std::vector<int>{4, 1, 2, 1, 2}) == 4);
    return 0;
}
