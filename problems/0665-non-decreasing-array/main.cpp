#include <cassert>
#include <vector>

bool checkPossibility(std::vector<int> &nums) {
    if (nums.size() <= 2) {
        return true;
    }

    size_t notDecreasing = 0;
    int prev = -1000000;
    for (size_t i = 0; i < nums.size() - 1; ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (nums[j] > nums[i]) {
                if (++notDecreasing >= 2) {
                    return false;
                }

                nums[i] = nums[i - 1];
                break;
            }
        }
        if (nums[i] > nums[i + 1]) {
            if (++notDecreasing >= 2) {
                return false;
            }

            if (prev >= nums[i + 1]) {
                nums[i + 1] = nums[i];
            } else {
                nums[i] = nums[i + 1];
            }
        }
        prev = nums[i];
    }

    return true;
}

int main() {
    {
        std::vector<int> input{4, 2, 3};
        assert(checkPossibility(input));
    }
    {
        std::vector<int> input{4, 2, 1};
        assert(!checkPossibility(input));
    }
    {
        std::vector<int> input{3, 4, 2, 3};
        assert(!checkPossibility(input));
    }
    {
        std::vector<int> input{2, 3, 3, 2, 4};
        assert(checkPossibility(input));
    }
    {
        std::vector<int> input{-1, 4, 2, 3};
        assert(checkPossibility(input));
    }
    return 0;
}
