#include <cassert>
#include <string>
#include <stack>

bool isValid(const std::string &s) {
    std::stack<char> st;
    for (char c : s) {
        switch (c) {
        case ')':
            if (!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                st.push(c);
            }
            break;
        case '}':
            if (!st.empty() && st.top() == '{') {
                st.pop();
            } else {
                st.push(c);
            }
            break;
        case ']':
            if (!st.empty() && st.top() == '[') {
                st.pop();
            } else {
                st.push(c);
            }
            break;
        default:
            st.push(c);
            break;
        }
    }

    return st.empty();
}

int main() {
    assert(isValid("()"));
    assert(isValid("()[]{}"));
    assert(!isValid("(]"));
    assert(!isValid("([)]"));
    assert(isValid("{[]}"));
    return 0;
}
