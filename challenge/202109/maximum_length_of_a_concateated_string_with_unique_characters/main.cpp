#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

int maxLength(const std::vector<std::string> &arr) {
    std::vector<std::string> candidates{""};
    int ret = 0;
    for (const auto &str : arr) {
        for (size_t i = 0; i < candidates.size(); ++i) {
            std::string tmp = candidates[i] + str;
            std::set<char> s(tmp.begin(), tmp.end());
            if (s.size() == tmp.size()) {
                candidates.push_back(tmp);
                ret = std::max(ret, static_cast<int>(tmp.size()));
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> arr{"un", "iq", "ue"};
        assert(maxLength(arr) == 4);
    }
    {
        std::vector<std::string> arr{"chr", "r", "act", "ers"};
        assert(maxLength(arr) == 6);
    }
    {
        std::vector<std::string> arr{"abcdefghijklmnopqrstuvwxyz"};
        assert(maxLength(arr) == 26);
    }
    {
        std::vector<std::string> arr{"aaaa"};
        assert(maxLength(arr) == 0);
    }
    {
        std::vector<std::string> arr{"a", "b", "c"};
        assert(maxLength(arr) == 3);
    }
    return 0;
}