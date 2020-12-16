#include <cassert>
#include <vector>
#include <map>

int singleNumber(const std::vector<int> &nums) {
    std::map<int, int> m;
    for (int n : nums) {
        ++m[n];
    }

    for (const auto &it : m) {
        if (it.second == 1) {
            return it.first;
        }
    }

    assert(!"never reach here");
    return -1;
}

int main() {
    assert((singleNumber(std::vector<int>{2, 2, 3, 2}) == 3));
    assert((singleNumber(std::vector<int>{0, 1, 0, 1, 0, 1, 99}) == 99));
    return 0;
}
