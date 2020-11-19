#include <cassert>
#include <string>
#include <stack>

bool isValid(const std::string &s) {
    std::stack<char> ps;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            ps.push(c);
        } else if (c == ')') {
            if (ps.empty() || ps.top() != '(') {
                return false;
            }

            ps.pop();
        } else if (c == '}') {
            if (ps.empty() || ps.top() != '{') {
                return false;
            }

            ps.pop();
        } else if (c == ']') {
            if (ps.empty() || ps.top() != '[') {
                return false;
            }

            ps.pop();
        }
    }

    return ps.empty();
}

int main() {
    assert(isValid("()"));
    assert(isValid("()[]{}"));
    assert(!isValid("(]"));
    assert(!isValid("([)]"));
    assert(isValid("{[]}"));
    assert(!isValid("]"));
    return 0;
}
