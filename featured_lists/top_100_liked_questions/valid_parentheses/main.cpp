#include <cassert>
#include <vector>
#include <string>

bool isValid(const std::string &s) {
    std::vector<char> stack;
    for (char c : s) {
        if (c == '{') {
            stack.push_back('{');
        } else if (c == '[') {
            stack.push_back('[');
        } else if (c == '(') {
            stack.push_back('(');
        } else if (c == '}') {
            if (!stack.empty() && stack.back() == '{') {
                stack.pop_back();
            } else {
                return false;
            }
        } else if (c == ']') {
            if (!stack.empty() && stack.back() == '[') {
                stack.pop_back();
            } else {
                return false;
            }
        } else if (c == ')') {
            if (!stack.empty() && stack.back() == '(') {
                stack.pop_back();
            } else {
                return false;
            }
        }
    }

    return stack.empty();
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