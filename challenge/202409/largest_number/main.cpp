#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

std::string largestNumber(const std::vector<int> &nums) {
    std::vector<std::string> v;
    for (int num : nums) {
        v.push_back(std::to_string(num));
    }

    std::sort(v.begin(), v.end(), [](const std::string &a, const std::string &b) { return a + b > b + a; });

    if (v[0] == "0") {
        return "0";
    }

    std::string ret;
    for (const std::string &s : v) {
        ret += s;
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{10, 2};
        auto ret = largestNumber(nums);
        assert(ret == "210");
    }
    {
        std::vector<int> nums{3, 30, 34, 5, 9};
        auto ret = largestNumber(nums);
        assert(ret == "9534330");
    }
    return 0;
}