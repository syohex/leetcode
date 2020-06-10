#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <functional>

std::vector<std::string> letterCasePermutation(const std::string &S) {
    std::function<void(const std::string &, size_t, const std::string &, std::vector<std::string> &)> f;
    f = [&f](const std::string &str, size_t pos, const std::string &v, std::vector<std::string> &ret) {
        if (pos == str.size()) {
            ret.push_back(v);
            return;
        }

        auto c = str[pos];
        if (c >= 'a' && c <= 'z') {
            f(str, pos + 1, v + c, ret);
            char upper = c - ('a' - 'A');
            f(str, pos + 1, v + upper, ret);
        } else if (c >= 'A' && c <= 'Z') {
            f(str, pos + 1, v + c, ret);
            char lower = c + ('a' - 'A');
            f(str, pos + 1, v + lower, ret);
        } else {
            f(str, pos + 1, v + c, ret);
        }
    };

    std::vector<std::string> ret;
    f(S, 0, "", ret);

    return ret;
}

bool check(const std::vector<std::string> &got, const std::vector<std::string> &expected) {
    if (got.size() != expected.size()) {
        return false;
    }

    std::set<std::string> a, b;
    for (size_t i = 0; i < got.size(); ++i) {
        a.insert(got[i]);
        b.insert(expected[i]);
    }

    return a == b;
}

int main() {
    {
        std::vector<std::string> expected{"a1b2", "a1B2", "A1b2", "A1B2"};
        auto ret = letterCasePermutation("a1b2");
        assert(check(ret, expected));
    }
    {
        std::vector<std::string> expected{"3z4", "3Z4"};
        auto ret = letterCasePermutation("3z4");
        assert(check(ret, expected));
    }
    {
        std::vector<std::string> expected{"12345"};
        auto ret = letterCasePermutation("12345");
        assert(check(ret, expected));
    }
    return 0;
}
