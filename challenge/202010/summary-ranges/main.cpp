#include <cassert>
#include <string>
#include <vector>
#include <cstdio>

std::vector<std::string> summaryRanges(const std::vector<int> &nums) {
    std::vector<std::string> ret;
    if (nums.empty()) {
        return ret;
    }

    if (nums.size() == 1) {
        ret.push_back(std::to_string(nums[0]));
        return ret;
    }

    int start = nums[0];
    int n = 0;
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] - 1 == nums[i - 1]) {
            ++n;
        } else {
            if (n == 0) {
                ret.push_back(std::to_string(start));
            } else {
                ret.push_back(std::to_string(start) + "->" + std::to_string(nums[i - 1]));
            }
            start = nums[i];
            n = 0;
        }
    }

    if (n == 0) {
        ret.push_back(std::to_string(nums.back()));
    } else {
        ret.push_back(std::to_string(start) + "->" + std::to_string(nums.back()));
    }

    return ret;
}

int main() {
    {
        std::vector<int> input{0, 1, 2, 4, 5, 7};
        auto ret = summaryRanges(input);
        assert((ret == std::vector<std::string>{"0->2", "4->5", "7"}));
    }
    {
        std::vector<int> input{0, 1, 2, 3, 4, 5};
        auto ret = summaryRanges(input);
        assert((ret == std::vector<std::string>{"0->5"}));
    }
    {
        std::vector<int> input{0, 2, 3, 4, 6, 8, 9};
        auto ret = summaryRanges(input);
        assert((ret == std::vector<std::string>{"0", "2->4", "6", "8->9"}));
    }
    {
        std::vector<int> input;
        auto ret = summaryRanges(input);
        assert((ret == std::vector<std::string>{}));
    }
    {
        std::vector<int> input{-1};
        auto ret = summaryRanges(input);
        assert((ret == std::vector<std::string>{"-1"}));
    }
    {
        std::vector<int> input{0};
        auto ret = summaryRanges(input);
        assert((ret == std::vector<std::string>{"0"}));
    }
    return 0;
}
