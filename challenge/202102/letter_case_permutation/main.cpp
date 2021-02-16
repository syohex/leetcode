#include <cassert>
#include <string>
#include <vector>
#include <functional>
#include <cctype>
#include <set>

std::vector<std::string> letterCasePermutation(const std::string &S) {
    std::vector<std::string> ret;
    std::function<void(const std::string &str, size_t pos, std::string &acc)> f;
    f = [&f, &ret](const std::string &str, size_t pos, std::string &acc) {
        if (pos >= str.size()) {
            ret.push_back(acc);
            return;
        }

        int c = str[pos];
        if (std::isalpha(c)) {
            acc[pos] = std::tolower(c);
            f(str, pos + 1, acc);
            acc[pos] = std::toupper(c);
            f(str, pos + 1, acc);
        } else {
            acc[pos] = c;
            f(str, pos + 1, acc);
        }
    };

    std::string acc(S.size(), '0');
    f(S, 0, acc);
    return ret;
}

void check(const std::vector<std::string> &got, const std::vector<std::string> &expected) {
    std::set<std::string> gs, es;
    for (const auto &s : got) {
        gs.insert(s);
    }
    for (const auto &s : expected) {
        es.insert(s);
    }

    assert(gs == es);
}

int main() {
    {
        std::string input("a1b2");
        std::vector<std::string> expected{"a1b2", "a1B2", "A1b2", "A1B2"};
        auto ret = letterCasePermutation(input);
        check(ret, expected);
    }
    {
        std::string input("3z4");
        std::vector<std::string> expected{"3z4", "3Z4"};
        auto ret = letterCasePermutation(input);
        check(ret, expected);
    }
    {
        std::string input("12345");
        std::vector<std::string> expected{"12345"};
        auto ret = letterCasePermutation(input);
        check(ret, expected);
    }
    {
        std::string input("0");
        std::vector<std::string> expected{"0"};
        auto ret = letterCasePermutation(input);
        check(ret, expected);
    }
    return 0;
}
