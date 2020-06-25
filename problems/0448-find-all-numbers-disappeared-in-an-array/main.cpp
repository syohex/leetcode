#include <cassert>
#include <vector>

std::vector<int> findDisappearedNumbers(const std::vector<int> &nums) {
    std::vector<int> ret(nums.size(), 1);
    for (size_t i = 0; i < nums.size(); ++i) {
        ret[nums[i] - 1] = 0;
    }

    int i = 1;
    for (auto it = ret.begin(); it != ret.end(); ++i) {
        if (*it == 0) {
            it = ret.erase(it);
        } else {
            *it = i;
            ++it;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> input{4, 3, 2, 7, 8, 2, 3, 1};
        auto ret = findDisappearedNumbers(input);
        assert((ret == std::vector<int>{5, 6}));
    }
    return 0;
}
