#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>

std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string> &strs) {
    if (strs.empty()) {
        return std::vector<std::vector<std::string>>{};
    }
    if (strs.size() == 1) {
        return std::vector<std::vector<std::string>>{strs};
    }

    std::vector<std::map<char, int>> ms;
    std::map<char, int> tmpM;
    for (size_t i = 0; i < strs.size(); ++i) {
        for (char c : strs[i]) {
            ++tmpM[c];
        }
        ms.push_back(tmpM);
        tmpM.clear();
    }

    std::vector<std::vector<std::string>> ret;
    std::vector<std::string> tmpV;
    std::set<size_t> s;
    for (size_t i = 0; i < strs.size(); ++i) {
        if (s.find(i) != s.end()) {
            continue;
        }

        tmpV.push_back(strs[i]);
        for (size_t j = i + 1; j < strs.size(); ++j) {
            if (ms[i] == ms[j]) {
                s.insert(j);
                tmpV.push_back(strs[j]);
            }
        }

        ret.push_back(tmpV);
        tmpV.clear();
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> input{"eat", "tea", "tan", "ate", "nat", "bat"};
        auto ret = groupAnagrams(input);
        assert(ret.size() == 3);
        assert((ret[0] == std::vector<std::string>{"eat", "tea", "ate"}));
        assert((ret[1] == std::vector<std::string>{"tan", "nat"}));
        assert((ret[2] == std::vector<std::string>{"bat"}));
    }
    return 0;
}
