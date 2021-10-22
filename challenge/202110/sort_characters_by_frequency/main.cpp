#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

std::string frequencySort(std::string &s) {
    std::map<char, int> m;
    for (char c : s) {
        ++m[c];
    }

    struct Data {
        char ch;
        int count;
    };
    std::vector<Data> v;
    for (const auto &it : m) {
        v.push_back({it.first, it.second});
    }

    std::sort(v.begin(), v.end(), [](const Data &a, const Data &b) -> bool { return a.count > b.count; });

    size_t pos = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].count; ++j) {
            s[pos++] = v[i].ch;
        }
    }

    return s;
}

int main() {
    {
        std::string s("tree");
        auto ret = frequencySort(s);
        assert(ret == "eert" || ret == "eetr");
    }
    {
        std::string s("cccaaa");
        auto ret = frequencySort(s);
        assert(ret == "aaaccc");
    }
    {
        std::string s("Aabb");
        auto ret = frequencySort(s);
        assert(ret == "bbAa" || ret == "bbaA");
    }
    return 0;
}
