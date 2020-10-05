#include <cassert>
#include <vector>
#include <cstdio>

int removeElement(std::vector<int> &nums, int val) {
    size_t deleted = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] == val) {
            deleted = 1;
            for (size_t j = i + 1; j < nums.size(); ++j) {
                if (nums[j] == val) {
                    ++deleted;
                    continue;
                }

                nums[j - deleted] = nums[j];
            }

            break;
        }
    }

    return static_cast<int>(nums.size() - deleted);
}

int main() {
    {
        std::vector<int> inputs{3, 2, 2, 3};
        assert(removeElement(inputs, 3) == 2);
    }
    {
        std::vector<int> inputs{0, 1, 2, 2, 3, 0, 4, 2};
        assert(removeElement(inputs, 2) == 5);
    }
    return 0;
}
