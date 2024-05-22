#include <cassert>
#include <vector>
#include <string>
#include <cstddef>
#include <functional>

std::vector<std::vector<std::string>> partiton(const std::string &s) {
    const auto is_palindrome = [](const std::string &t) -> bool {
        std::size_t len = t.size();
        std::size_t limit = len / 2;

        for (std::size_t i = 0; i <= limit; ++i) {
            if (t[i] != t[len - 1 - i]) {
                return false;
            }
        }

        return true;
    };

    std::vector<std::vector<std::string>> ret;

    std::function<void(std::size_t pos, std::vector<std::string> & acc)> f;
    f = [&](std::size_t pos, std::vector<std::string> &acc) {
        if (pos == s.size()) {
            ret.push_back(acc);
            return;
        }

        std::string tmp;
        for (std::size_t i = pos; i < s.size(); ++i) {
            tmp.push_back(s[i]);
            if (is_palindrome(tmp)) {
                acc.push_back(tmp);
                f(i + 1, acc);
                acc.pop_back();
            }
        }
    };

    std::vector<std::string> acc;
    f(0, acc);
    return ret;
}

int main() {
    {
        std::string s("aab");
        std::vector<std::vector<std::string>> expected{{"a", "a", "b"}, {"aa", "b"}};
        auto ret = partiton(s);
        assert(ret == expected);
    }
    {
        std::string s("a");
        std::vector<std::vector<std::string>> expected{{"a"}};
        auto ret = partiton(s);
        assert(ret == expected);
    }
    return 0;
}
