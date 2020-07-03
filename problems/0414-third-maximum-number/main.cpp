#include <cassert>
#include <vector>

int thirdMax(const std::vector<int> &nums) {
    int first = nums[0], second, third;
    bool hasSecond = false, hasThird = false;
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] > first) {
            if (hasSecond) {
                hasThird = true;
                third = second;
                second = first;
            } else {
                hasSecond = true;
                second = first;
            }
            first = nums[i];
        } else if (nums[i] == first) {
            continue;
        } else {
            if (hasSecond) {
                if (nums[i] > second) {
                    hasThird = true;
                    third = second;
                    second = nums[i];
                } else if (nums[i] == second) {
                    continue;
                } else {
                    if (hasThird) {
                        if (nums[i] > third) {
                            third = nums[i];
                        }
                    } else {
                        hasThird = true;
                        third = nums[i];
                    }
                }
            } else {
                second = nums[i];
                hasSecond = true;
            }
        }
    }

    if (!hasThird) {
        return first;
    }

    return third;
}

int main() {
    {
        std::vector<int> input{3, 2, 1};
        assert(thirdMax(input) == 1);
    }
    {
        std::vector<int> input{1, 2};
        assert(thirdMax(input) == 2);
    }
    {
        std::vector<int> input{2, 2, 3, 1};
        assert(thirdMax(input) == 1);
    }
    {
        std::vector<int> input{1, 2, 2, 5, 3, 5};
        assert(thirdMax(input) == 2);
    }
    {
        std::vector<int> input{1, -2147483648, 2};
        assert(thirdMax(input) == -2147483648);
    }
    return 0;
}
