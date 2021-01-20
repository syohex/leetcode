#include <cassert>
#include <string>
#include <stack>

bool isValid(const std::string &s) {
    std::stack<char> stack;
    for (char c : s) {
        switch (c) {
        case '[':
        case '(':
        case '{':
            stack.push(c);
            break;
        case ']':
            if (stack.empty() || stack.top() != '[') {
                return false;
            }
            stack.pop();
            break;
        case ')':
            if (stack.empty() || stack.top() != '(') {
                return false;
            }
            stack.pop();
            break;
        case '}':
            if (stack.empty() || stack.top() != '{') {
                return false;
            }
            stack.pop();
            break;
        default:
            break;
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
