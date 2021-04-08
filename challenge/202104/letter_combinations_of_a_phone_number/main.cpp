#include <cassert>
#include <vector>
#include <string>
#include <functional>
#include <map>

std::vector<std::string> letterCombinations(const std::string &digits) {
    std::vector<std::string> ret;
    if (digits.empty()) {
        return ret;
    }

    const std::map<char, std::string> m{
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };
    std::function<void(const std::string &str, size_t pos, const std::string &acc)> f;
    f = [&f, &m, &ret](const std::string &str, size_t pos, const std::string &acc) {
        if (pos >= str.size()) {
            ret.push_back(acc);
            return;
        }

        for (char c : m.at(str[pos])) {
            f(str, pos + 1, acc + c);
        }
    };

    f(digits, 0, "");
    return ret;
}

int main() {
    {
        std::vector<std::string> expected{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
        auto ret = letterCombinations("23");
        assert(ret == expected);
    }
    {
        std::vector<std::string> expected{};
        auto ret = letterCombinations("");
        assert(ret == expected);
        assert(ret.empty());
    }
    {
        std::vector<std::string> expected{"a", "b", "c"};
        auto ret = letterCombinations("2");
        assert(ret == expected);
    }
    return 0;
}
