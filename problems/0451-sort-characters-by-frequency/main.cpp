#include <cassert>
#include <string>
#include <cstdio>
#include <map>
#include <vector>
#include <functional>
#include <set>

std::string frequencySort(const std::string &s) {
    std::map<char, int> m;
    for (char c : s) {
        ++m[c];
    }

    std::map<int, std::vector<char>> freqChars;
    std::set<int, std::greater<int>> freqs;
    for (const auto &it : m) {
        freqChars[it.second].push_back(it.first);
        freqs.insert(it.second);
    }

    std::string ret;
    ret.resize(s.size());
    size_t index = 0;
    for (int freq : freqs) {
        for (char c : freqChars[freq]) {
            for (size_t i = 0; i < freq; ++i) {
                ret[index++] = c;
            }
        }
    }

    return ret;
}

int main() {
    {
        auto ret = frequencySort("tree");
        assert((ret == "eert" || ret == "eetr"));
    }
    {
        auto ret = frequencySort("cccaaa");
        assert((ret == "cccaaa" || ret == "aaaccc"));
    }
    {
        auto ret = frequencySort("Aabb");
        assert((ret == "bbaA" || ret == "bbAa"));
    }
    return 0;
}
