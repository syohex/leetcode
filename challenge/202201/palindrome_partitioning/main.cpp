#include <cassert>
#include <string>
#include <vector>
#include <set>
#include <functional>
#include <cstdio>

std::vector<std::vector<std::string>> partiton(const std::string &s) {
    const auto isPalindrome = [](const std::string &s) {
        if (s.size() <= 1) {
            return true;
        }

        int len = s.size();
        int limit = s.size() / 2;
        for (int i = 0; i <= limit; ++i) {
            if (s[i] != s[len - 1 - i]) {
                return false;
            }
        }

        return true;
    };

    std::vector<std::vector<std::string>> ret;
    std::set<std::string> cache;
    std::function<void(size_t pos, std::vector<std::string> & acc)> f;
    f = [&](size_t pos, std::vector<std::string> &acc) {
        if (pos >= s.size()) {
            ret.push_back(acc);
            return;
        }

        std::string base;
        base.push_back(s[pos]);

        acc.push_back(base);
        f(pos + 1, acc);
        acc.pop_back();

        for (size_t i = pos + 1; i < s.size(); ++i) {
            base.push_back(s[i]);
            if (cache.find(base) != cache.end() || isPalindrome(base)) {
                cache.insert(base);

                acc.push_back(base);
                f(i + 1, acc);
                acc.pop_back();
            }
        }
    };

    std::vector<std::string> acc;
    f(0, acc);
    return ret;
}

void check(const std::vector<std::vector<std::string>> &got, const std::vector<std::vector<std::string>> &expected) {
    assert(got.size() == expected.size());

    std::set<std::vector<std::string>> gs(got.begin(), got.end());
    std::set<std::vector<std::string>> es(expected.begin(), expected.end());
    assert(gs == es);
}

int main() {
    {
        std::vector<std::vector<std::string>> expected{
            {"a", "a", "b"},
            {"aa", "b"},
        };

        auto ret = partiton("aab");
        check(ret, expected);
    }
    {
        std::vector<std::vector<std::string>> expected{
            {"a"},
        };

        auto ret = partiton("a");
        check(ret, expected);
    }
    {
        std::vector<std::vector<std::string>> expected{
            {"e", "f", "e"},
            {"efe"},
        };

        auto ret = partiton("efe");
        check(ret, expected);
    }
    return 0;
}
