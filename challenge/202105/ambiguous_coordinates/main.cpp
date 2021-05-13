#include <cassert>
#include <vector>
#include <string>
#include <set>

std::vector<std::string> ambiguousCoordinates(const std::string &s) {
    const auto f = [](const std::string &str) -> std::vector<std::string> {
        int len = str.size();
        if (len == 1) {
            return std::vector<std::string>{str};
        }

        std::vector<std::string> v;
        if (str.front() == '0') {
            if (str.back() == '0') {
                return std::vector<std::string>{};
            }

            return std::vector<std::string>{"0." + str.substr(1)};
        }

        v.push_back(str);

        for (int i = 1; i < len; ++i) {
            std::string latter = str.substr(i);
            if (latter.back() == '0') {
                continue;
            }

            v.push_back(str.substr(0, i) + "." + latter);
        }

        return v;
    };

    std::vector<std::string> ret;
    std::string str = s.substr(1, s.size() - 2); // remove parenthesis
    int len = str.size();
    for (int i = 1; i < len; ++i) {
        auto fronts = f(str.substr(0, i));
        auto backs = f(str.substr(i));

        for (const auto &front : fronts) {
            for (const auto &back : backs) {
                ret.push_back("(" + front + ", " + back + ")");
            }
        }
    }

    return ret;
}

void check(const std::vector<std::string> &got, const std::vector<std::string> &expected) {
    std::set<std::string> gs(got.begin(), got.end());
    std::set<std::string> es(got.begin(), got.end());
    assert(gs == es);
}

int main() {
    {
        std::vector<std::string> expected{"(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"};
        auto ret = ambiguousCoordinates("(123)");
        check(ret, expected);
    }
    {
        std::vector<std::string> expected{"(0.001, 1)", "(0, 0.011)"};
        auto ret = ambiguousCoordinates("(00011)");
        check(ret, expected);
    }
    {
        std::vector<std::string> expected{"(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"};
        auto ret = ambiguousCoordinates("(0123)");
        check(ret, expected);
    }
    {
        std::vector<std::string> expected{"(10, 0)"};
        auto ret = ambiguousCoordinates("(100)");
        check(ret, expected);
    }
    {
        std::vector<std::string> expected{"(1, 2.3)", "(1, 23)", "(1.2, 3)", "(12, 3)"};
        auto ret = ambiguousCoordinates("(123)");
        check(ret, expected);
    }
    return 0;
}
