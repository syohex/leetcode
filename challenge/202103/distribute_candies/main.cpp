#include <cassert>
#include <vector>
#include <set>
#include <algorithm>

int distributeCandies(const std::vector<int> &candyType) {
    std::set<int> s;
    for (int n : candyType) {
        s.insert(n);
    }

    return static_cast<int>(std::min(candyType.size() / 2, s.size()));
}

int main() {
    assert((distributeCandies(std::vector<int>{1, 1, 2, 2, 3, 3}) == 3));
    assert((distributeCandies(std::vector<int>{1, 1, 2, 3}) == 2));
    assert((distributeCandies(std::vector<int>{6, 6, 6, 6}) == 1));
    return 0;
}
