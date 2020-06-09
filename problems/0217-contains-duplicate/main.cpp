#include <cassert>
#include <vector>
#include <set>

bool containsDuplicate(const std::vector<int> &nums) {
    std::set<int> s;
    for (const auto n : nums) {
        if (s.find(n) != s.end()) {
            return true;
        }

        s.insert(n);
    }

    return false;
}

int main() {
    assert(!(containsDuplicate(std::vector<int>{})));
    assert(!(containsDuplicate(std::vector<int>{1})));
    assert((containsDuplicate(std::vector<int>{1, 1})));
    assert((containsDuplicate(std::vector<int>{1, 2, 3, 1})));
    assert(!(containsDuplicate(std::vector<int>{1, 2, 3, 4})));
    assert((containsDuplicate(std::vector<int>{1, 1, 1, 3, 3, 4, 3, 2, 4, 2})));
    return 0;
}
