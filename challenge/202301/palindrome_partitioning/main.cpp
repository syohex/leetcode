#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <functional>

std::vector<std::vector<std::string>> partition(const std::string &s) {
    const auto is_palindrome = [](const std::string &s) -> bool {
        size_t len = s.size() / 2;
        for (size_t i = 0; i < len; ++i) {
            if (s[i] != s[s.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    };

    std::vector<std::vector<std::string>> ret;
    std::function<void(size_t pos, std::vector<std::string> & acc)> f;
    f = [&](size_t pos, std::vector<std::string> &acc) {
        if (pos >= s.size()) {
            ret.push_back(acc);
            return;
        }

        std::string base;
        for (size_t i = pos; i < s.size(); ++i) {
            base.push_back(s[i]);
            if (is_palindrome(base)) {
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

int main() {
    {
        std::string s("aab");
        std::vector<std::vector<std::string>> expected{{"a", "a", "b"}, {"aa", "b"}};
        auto ret = partition(s);
        assert(ret == expected);
    }
    {
        std::string s("a");
        std::vector<std::vector<std::string>> expected{{"a"}};
        auto ret = partition(s);
        assert(ret == expected);
    }
    return 0;
}
