#include <cassert>
#include <string>
#include <vector>
#include <functional>
#include <map>

bool wordBreak(const std::string &s, const std::vector<std::string> &wordDict) {
    std::map<size_t, bool> cache;

    std::function<bool(size_t pos)> f;
    f = [&](size_t pos) -> bool {
        if (pos >= s.size()) {
            return true;
        }

        if (cache.find(pos) != cache.end()) {
            return cache[pos];
        }

        for (size_t i = pos + 1; i <= s.size(); ++i) {
            std::string substr = s.substr(pos, i - pos);
            if (std::find(wordDict.begin(), wordDict.end(), substr) == wordDict.end()) {
                continue;
            }

            if (f(i)) {
                cache[i + 1] = true;
                return true;
            }
        }

        cache[pos] = false;
        return false;
    };

    return f(0);
}

int main() {
    {
        std::vector<std::string> wordDict{"leet", "code"};
        assert(wordBreak("leetcode", wordDict));
    }
    {
        std::vector<std::string> wordDict{"apple", "pen"};
        assert(wordBreak("applepenapple", wordDict));
    }
    {
        std::vector<std::string> wordDict{"cats", "dog", "sand", "and", "cat"};
        assert(!wordBreak("catsandog", wordDict));
    }
    return 0;
}