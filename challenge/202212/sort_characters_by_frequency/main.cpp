#include <cassert>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

std::string frequencySort(const std::string &s) {
    std::map<char, int> m;
    for (char c : s) {
        ++m[c];
    }

    std::vector<std::pair<char, int>> v;
    for (const auto &it : m) {
        v.push_back({it.first, it.second});
    }

    std::sort(v.begin(), v.end(), [](const std::pair<char, int> &a, const std::pair<char, int> &b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second > b.second;
    });

    std::string ret;
    for (const auto &p : v) {
        for (int i = 0; i < p.second; ++i) {
            ret.push_back(p.first);
        }
    }

    return ret;
}

int main() {
    {
        std::string s("tree");
        auto ret = frequencySort(s);
        assert(ret == "eert");
    }
    {
        std::string s("cccaaa");
        auto ret = frequencySort(s);
        assert(ret == "aaaccc");
    }
    {
        std::string s("Aabb");
        auto ret = frequencySort(s);
        assert(ret == "bbAa");
    }
    return 0;
}
