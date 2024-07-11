#include <cassert>
#include <string>
#include <algorithm>
#include <functional>

std::string reverseParentheses(const std::string &s) {
    std::function<std::string(std::size_t & pos)> f;
    f = [&](std::size_t &pos) -> std::string {
        std::string ret;
        while (pos < s.size()) {
            if (s[pos] == '(') {
                ++pos;
                ret.append(f(pos));
            } else if (s[pos] == ')') {
                std::reverse(ret.begin(), ret.end());
                ++pos;
                break;
            } else {
                ret.push_back(s[pos]);
                ++pos;
            }
        }

        return ret;
    };

    std::size_t pos = 0;
    return f(pos);
}

int main() {
    assert(reverseParentheses("(abcd)") == "dcba");
    assert(reverseParentheses("(u(love)i)") == "iloveu");
    assert(reverseParentheses("(ed(et(oc))el)") == "leetcode");
    return 0;
}
