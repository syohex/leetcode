#include <cassert>
#include <vector>
#include <string>
#include <functional>
#include <set>
#include <map>
#include <algorithm>

int minExtraChar(const std::string &s, const std::vector<std::string> &dictionary) {
    int len = s.size();
    std::set<std::string> words(dictionary.begin(), dictionary.end());
    std::map<int, int> cache;

    std::function<int(int pos)> f = [&](int pos) -> int {
        if (pos >= len) {
            return 0;
        }

        if (cache.find(pos) != cache.end()) {
            return cache.at(pos);
        }

        int ret = f(pos + 1) + 1;
        for (int i = pos; i < len; ++i) {
            std::string tmp = s.substr(pos, i - pos + 1);
            if (words.find(tmp) != words.end()) {
                ret = std::min(ret, f(i + 1));
            }
        }

        cache[pos] = ret;
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
