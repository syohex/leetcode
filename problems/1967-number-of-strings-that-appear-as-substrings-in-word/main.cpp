#include <cassert>
#include <vector>
#include <string>

int numOfStrings(const std::vector<std::string> &patterns, const std::string &word) {
    int ret = 0;
    for (const auto &pattern : patterns) {
        if (word.find(pattern) != std::string::npos) {
            ++ret;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> patterns{"a", "abc", "bc", "d"};
        assert(numOfStrings(patterns, "abc") == 3);
    }
    {
        std::vector<std::string> patterns{"a", "b", "c"};
        assert(numOfStrings(patterns, "aaaaabbbbb") == 2);
    }
    {
        std::vector<std::string> patterns{"a", "a", "a"};
        assert(numOfStrings(patterns, "ab") == 3);
    }
    return 0;
}