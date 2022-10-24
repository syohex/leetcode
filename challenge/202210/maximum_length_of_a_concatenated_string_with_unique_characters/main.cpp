#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

int maxLength(const std::vector<std::string> &arr) {
    std::vector<std::string> candidates{""};
    int ret = 0;

    for (const std::string &word : arr) {
        int len = candidates.size();
        for (int i = 0; i < len; ++i) {
            std::string tmp = word + candidates[i];
            std::set<char> s(tmp.begin(), tmp.end());

            if (s.size() == tmp.size()) {
                ret = std::max(ret, static_cast<int>(tmp.size()));
                candidates.push_back(tmp);
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> arr{"un", "iq", "ue"};
        int ret = maxLength(arr);
        assert(ret == 4);
    }
    {
        std::vector<std::string> arr{"cha", "r", "act", "ers"};
        int ret = maxLength(arr);
        assert(ret == 6);
    }
    {
        std::vector<std::string> arr{"abcdefghijklmnopqrstuvwxyz"};
        int ret = maxLength(arr);
        assert(ret == 26);
    }
    return 0;
}
