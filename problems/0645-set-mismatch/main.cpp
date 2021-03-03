#include <cassert>
#include <vector>

std::vector<int> findErrorNums(const std::vector<int> &nums) {
    std::vector<int> v(nums.size(), 0);
    for (const auto num : nums) {
        v[num - 1] = v[num - 1] + 1;
    }

    int duplicated = 0;
    int missed = 0;
    for (int i = 1; i <= static_cast<int>(nums.size()); ++i) {
        if (v[i - 1] == 2) {
            duplicated = i;
        } else if (v[i - 1] == 0) {
            missed = i;
        }
    }

    return std::vector<int>{duplicated, missed};
}

int main() {
    assert((findErrorNums(std::vector<int>{1, 2, 2, 4}) == std::vector<int>{2, 3}));
    assert((findErrorNums(std::vector<int>{1, 1}) == std::vector<int>{1, 2}));
    return 0;
}
