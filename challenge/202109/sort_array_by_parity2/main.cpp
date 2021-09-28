#include <cassert>
#include <vector>
#include <algorithm>

std::vector<int> sortArrayByParityII(std::vector<int> &nums) {
    int len = nums.size();
    for (int i = 0; i < len; ++i) {
        if (i % 2 == 0) {
            if (nums[i] % 2 != 0) {
                int j = len - 1;
                for (; j > i; --j) {
                    if (nums[j] % 2 == 0) {
                        std::swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        } else {
            if (nums[i] % 2 == 0) {
                int j = len - 1;
                for (; j > i; --j) {
                    if (nums[j] % 2 == 1) {
                        std::swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }
    }

    return nums;
}

void check(const std::vector<int> &v) {
    printf("[");
    for (size_t i = 0; i < v.size(); ++i) {
        assert(i % 2 == 0 ? v[i] % 2 == 0 : v[i] % 2 == 1);
        printf(" %d ", v[i]);
    }
    printf("]\n");
}

int main() {
    {
        std::vector<int> nums{4, 2, 5, 7};
        check(sortArrayByParityII(nums));
    }
    {
        std::vector<int> nums{2, 3};
        check(sortArrayByParityII(nums));
    }
    return 0;
}