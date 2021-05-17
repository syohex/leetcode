#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <map>
#include <set>

int longestStrChain(const std::vector<std::string> &words) {
    std::set<std::string> s(words.begin(), words.end());
    std::map<std::string, int> cache;

    std::function<int(const std::string &str)> f;
    f = [&f, &s, &cache](const std::string &str) -> int {
        if (cache.find(str) != cache.end()) {
            return cache[str];
        }

        int lens = str.size();
        std::string tmp;
        int ret = 1;
        for (int i = 0; i < lens; ++i) {
            if (i == 0) {
                tmp = str.substr(1);
            } else if (i == lens - 1) {
                tmp = str.substr(0, lens - 1);
            } else {
                tmp = str.substr(0, i) + str.substr(i + 1);
            }

            if (s.find(tmp) != s.end()) {
                ret = std::max(ret, 1 + f(tmp));
            }
        }

        cache[str] = ret;
        return ret;
    };

    int ret = 0;
    for (const auto &word : words) {
        ret = std::max(ret, f(word));
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> words{"a", "b", "ba", "bca", "bda", "bdca"};
        assert(longestStrChain(words) == 4);
    }
    {
        std::vector<std::string> words{"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
        assert(longestStrChain(words) == 5);
    }
    return 0;
}
