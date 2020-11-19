#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

std::string longestCommonPrefix(const std::vector<std::string> &strs) {
    if (strs.empty()) {
        return "";
    }

    if (strs.size() == 1) {
        return strs[0];
    }

    size_t min_len = SIZE_MAX;
    for (const auto &s : strs) {
        min_len = std::min(min_len, s.size());
    }

    std::string ret;
    for (size_t i = 0; i < min_len; ++i) {
        char c = strs[0][i];
        for (size_t j = 1; j < strs.size(); ++j) {
            if (strs[j][i] != c) {
                return ret;
            }
        }

        ret.push_back(c);
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> strs{"flower", "flow", "flight"};
        assert(longestCommonPrefix(strs) == "fl");
    }
    {
        std::vector<std::string> strs{"dog", "racecar", "car"};
        assert(longestCommonPrefix(strs) == "");
    }
    {
        std::vector<std::string> strs{"dog"};
        assert(longestCommonPrefix(strs) == "dog");
    }
    {
        std::vector<std::string> strs{};
        assert(longestCommonPrefix(strs) == "");
    }
    return 0;
}
