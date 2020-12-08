#include <cassert>
#include <vector>
#include <string>
#include <functional>

std::vector<std::string> letterCombinations(const std::string &digits) {
    std::vector<std::string> ret;

    const std::vector<std::vector<char>> numbers{
        {'a', 'b', 'c'}, {'d', 'e', 'f'},      {'g', 'h', 'i'}, {'j', 'k', 'l'},
        {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'},
    };

    std::function<void(const std::string &s, size_t pos)> f;
    f = [&f, &numbers, &ret](const std::string &s, size_t pos) {
        if (pos == s.size()) {
            return;
        }

        int num = s[pos] - '2';
        if (ret.empty()) {
            for (const auto c : numbers[num]) {
                ret.emplace_back(1, c);
            }
        } else {
            std::vector<std::string> tmp;
            for (const auto &ss : ret) {
                for (const auto c : numbers[num]) {
                    tmp.push_back(ss + c);
                }
            }
            ret = std::move(tmp);
        }

        f(s, pos + 1);
    };

    f(digits, 0);
    return ret;
}

int main() {
    {
        auto ret = letterCombinations("23");
        std::vector<std::string> expected{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
        assert(ret == expected);
    }
    {
        auto ret = letterCombinations("");
        assert(ret.empty());
    }
    {
        auto ret = letterCombinations("2");
        std::vector<std::string> expected{"a", "b", "c"};
        assert(ret == expected);
    }
    {
        auto ret = letterCombinations("2345");
        assert(ret.size() == 81);
    }
    return 0;
}
