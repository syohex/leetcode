#include <cassert>
#include <string>
#include <vector>

std::string longestCommonPrefix(const std::vector<std::string> &strs) {
    if (strs.empty()) {
        return "";
    }

    if (strs.size() == 1) {
        return strs[0];
    }

    size_t longest = strs[0].size();
    for (size_t i = 1; i < strs.size(); ++i) {
        size_t j;
        for (j = 0; j < longest && j < strs[i].size(); ++j) {
            if (strs[0][j] != strs[i][j]) {
                break;
            }
        }

        if (j < longest) {
            longest = j;
        }
    }

    return strs[0].substr(0, longest);
}

int main() {
    assert(longestCommonPrefix(std::vector<std::string>{""}) == "");
    assert(longestCommonPrefix(std::vector<std::string>{"apple"}) == "apple");
    assert(longestCommonPrefix(std::vector<std::string>{"flower", "flow", "flight"}) == "fl");
    assert(longestCommonPrefix(std::vector<std::string>{"flower", "flower", "flow"}) == "flow");
    assert(longestCommonPrefix(std::vector<std::string>{"dog", "racecar", "car"}) == "");
    assert(longestCommonPrefix(std::vector<std::string>{"baab", "bacb", "b", "cbc"}) == "");
    return 0;
}