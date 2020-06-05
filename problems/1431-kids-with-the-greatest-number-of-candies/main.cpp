#include <cassert>
#include <vector>

std::vector<bool> kidsWithCandies(const std::vector<int> &candies, int extraCandies) {
    int max = candies[0];
    for (size_t i = 1; i < candies.size(); ++i) {
        if (max < candies[i]) {
            max = candies[i];
        }
    }

    std::vector<bool> ret(candies.size(), false);
    for (size_t i = 0; i < candies.size(); ++i) {
        ret[i] = candies[i] + extraCandies >= max;
    }

    return ret;
}

int main() {
    assert((kidsWithCandies(std::vector<int>{2, 3, 5, 1, 3}, 3) == std::vector<bool>{true, true, true, false, true}));
    assert((kidsWithCandies(std::vector<int>{4, 2, 1, 1, 2}, 1) == std::vector<bool>{true, false, false, false, false}));
    return 0;
}