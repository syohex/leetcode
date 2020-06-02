#include <cassert>
#include <cstdio>
#include <vector>

int removeDuplicates(std::vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }

    int uniques = 1;
    size_t unique_index = 1;
    int current = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        if (current == nums[i]) {
            continue;
        }

        nums[unique_index++] = nums[i];
        ++uniques;
        current = nums[i];
    }

    return uniques;
}

bool check(int n, const std::vector<int> &nums, const std::vector<int> &expected) {
    return std::equal(nums.begin(), nums.begin() + n, expected.begin());
}

void print(int n, const std::vector<int> &nums) {
    printf("[");
    for (int i = 0; i < n; ++i) {
        printf(" %d ", nums[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    std::vector<int> input{1, 1, 2};
    int ret = removeDuplicates(input);
    assert(check(ret, input, std::vector<int>{1, 2}));

    input = std::vector<int>{};
    ret = removeDuplicates(input);
    assert(ret == 0);

    input = std::vector<int>{9};
    ret = removeDuplicates(input);
    assert(check(ret, input, std::vector<int>{9}));

    input = std::vector<int>{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    ret = removeDuplicates(input);
    assert(check(ret, input, std::vector<int>{0, 1, 2, 3, 4}));
    return 0;
}
