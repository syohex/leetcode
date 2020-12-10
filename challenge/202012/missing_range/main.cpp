#include <cassert>
#include <vector>
#include <string>

std::vector<std::string> findMissingRanges(const std::vector<int> &nums, int lower, int upper) {
    const auto to_range_string = [](int from, int to) -> std::string {
        std::string tmp(std::to_string(from));
        tmp += "->";
        tmp += std::to_string(to);
        return tmp;
    };

    std::vector<std::string> ret;
    if (nums.empty()) {
        if (upper == lower) {
            ret.push_back(std::to_string(lower));
        } else {
            ret.push_back(to_range_string(lower, upper));
        }

        return ret;
    }

    if (lower < nums[0]) {
        if (nums[0] - lower == 1) {
            ret.push_back(std::to_string(lower));
        } else {
            ret.push_back(to_range_string(lower, nums[0] - 1));
        }
    }

    for (size_t i = 0; i < nums.size() - 1; ++i) {
        int diff = nums[i + 1] - nums[i];
        switch (diff) {
        case 1:
            break;
        case 2:
            ret.push_back(std::to_string(nums[i] + 1));
            break;
        default:
            ret.push_back(to_range_string(nums[i] + 1, nums[i + 1] - 1));
            break;
        }
    }

    if (upper > nums.back()) {
        if (upper - nums.back() == 1) {
            ret.push_back(std::to_string(upper));
        } else {
            ret.push_back(to_range_string(nums.back() + 1, upper));
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{0, 1, 3, 50, 75};
        std::vector<std::string> expected{"2", "4->49", "51->74", "76->99"};
        auto ret = findMissingRanges(nums, 0, 99);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{};
        std::vector<std::string> expected{"1"};
        auto ret = findMissingRanges(nums, 1, 1);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{};
        std::vector<std::string> expected{"-3->-1"};
        auto ret = findMissingRanges(nums, -3, -1);
        assert(ret == expected);
    }
    {
        std::vector<int> nums{-1};
        auto ret = findMissingRanges(nums, -1, -1);
        assert(ret.empty());
    }
    {
        std::vector<int> nums{-1};
        std::vector<std::string> expected{"-2"};
        auto ret = findMissingRanges(nums, -2, -1);
        assert(ret == expected);
    }
    return 0;
}
