#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

int maximumProduct(std::vector<int> &nums) {
    if (nums.size() == 3) {
        return nums[0] * nums[1] * nums[2];
    }

    std::sort(nums.begin(), nums.end(), [](int x, int y) { return x > y; });

    int positives = 0;
    int negatives = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) {
            ++positives;
        } else if (nums[i] < 0) {
            ++negatives;
        }
    }

    if (positives >= 1 && negatives >= 2) {
        size_t end = nums.size() - 1;
        int mulPos = nums[1] * nums[2];
        int mulNeg = nums[end - 1] * nums[end];

        if (mulPos < mulNeg) {
            return nums[0] * nums[end - 1] * nums[end];
        }
    }

    return nums[0] * nums[1] * nums[2];
}

int main() {
    {
        std::vector<int> input{1, 2, 3};
        assert(maximumProduct(input) == 6);
    }
    {
        std::vector<int> input{1, 2, 3, 4};
        assert(maximumProduct(input) == 24);
    }
    {
        std::vector<int> input{-4, -3, -2, -1, 60};
        assert(maximumProduct(input) == 720);
    }
    {
        std::vector<int> input{
            -710, -107, -851, 657,  -14,  -859, 278, -182, -749, 718, -640, 127,  -930, -462, 694,  969,  143,  309,  904,  -651,
            160,  451,  -159, -316, 844,  -60,  611, -169, -73,  721, -902, 338,  -20,  -890, -819, -644, 107,  404,  150,  -219,
            459,  -324, -385, -118, -307, 993,  202, -147, 62,   -94, -976, -329, 689,  870,  532,  -686, 371,  -850, -186, 87,
            878,  989,  -822, -350, -948, -412, 161, -88,  -509, 836, -207, -60,  771,  516,  -287, -366, -512, 509,  904,  -459,
            683,  -563, -766, -837, -333, 93,   893, 303,  908,  532, -206, 990,  280,  826,  -13,  115,  -732, 525,  -939, -787,
        };
        assert(maximumProduct(input) == 972256230);
    }

    return 0;
}
