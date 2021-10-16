#include <cassert>
#include <vector>
#include <string>
#include <map>

int numOfPairs(const std::vector<std::string> &nums, const std::string &target) {
    std::map<std::string, std::vector<size_t>> m;
    for (size_t i = 0; i < nums.size(); ++i) {
        m[nums[i]].push_back(i);
    }

    int ret = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        size_t pos = target.find(nums[i]);
        if (pos != 0) {
            continue;
        }

        auto rest = target.substr(nums[i].size());
        if (m.find(rest) != m.end()) {
            for (auto j : m[rest]) {
                if (i != j) {
                    ++ret;
                }
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> nums{"777", "7", "77", "77"};
        assert(numOfPairs(nums, "7777") == 4);
    }
    {
        std::vector<std::string> nums{"123", "4", "12", "34"};
        assert(numOfPairs(nums, "1234") == 2);
    }
    {
        std::vector<std::string> nums{"1", "1", "1"};
        assert(numOfPairs(nums, "11") == 6);
    }
    return 0;
}