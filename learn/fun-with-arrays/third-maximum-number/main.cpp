#include <cassert>
#include <vector>
#include <set>

int thirdMax(const std::vector<int> &nums) {
    std::set<int, std::greater<int>> s;
    for (auto num : nums) {
        s.insert(num);
    }

    if (s.size() < 3) {
        return *(s.begin());
    }

    auto it = s.begin();
    ++it;
    ++it;
    return *it;
}

int main() {
    assert((thirdMax(std::vector<int>{3, 2, 1}) == 1));
    assert((thirdMax(std::vector<int>{1, 2}) == 2));
    assert((thirdMax(std::vector<int>{2, 2, 3, 1}) == 1));
    return 0;
}
