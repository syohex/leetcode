#include <cassert>
#include <string>
#include <vector>
#include <functional>
#include <unordered_set>
#include <map>
#include <algorithm>

int minExtraChar(const std::string &s, const std::vector<std::string> &dictionary) {
    std::unordered_set<std::string> dict(dictionary.begin(), dictionary.end());
    std::map<int, int> cache;
    int len = s.size();

    std::function<int(int i)> f = [&](int i) -> int {
        if (i >= len) {
            return 0;
        }

        if (cache.find(i) != cache.end()) {
            return cache[i];
        }

        int ret = f(i + 1) + 1;
        for (int j = i; j < len; ++j) {
            std::string tmp = s.substr(i, j - i + 1);
            if (dict.find(tmp) != dict.end()) {
                ret = std::min(ret, f(j + 1));
            }
        }

        cache[i] = ret;
        return ret;
    };

    return f(0);
}

int main() {
    {
        std::string s = "leetscode";
        std::vector<std::string> dictionary{"leet", "code", "leetcode"};
        int ret = minExtraChar(s, dictionary);
        assert(ret == 1);
    }
    {
        std::string s = "sayhelloworld";
        std::vector<std::string> dictionary{"hello", "world"};
        int ret = minExtraChar(s, dictionary);
        assert(ret == 3);
    }
    return 0;
}
