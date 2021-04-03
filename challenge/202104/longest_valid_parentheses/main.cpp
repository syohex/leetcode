#include <cassert>
#include <string>
#include <stack>
#include <algorithm>

int longestValidParentheses(const std::string &s) {
    std::stack<int> stack;
    stack.push(-1);

    int ret = 0;
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        if (s[i] == '(') {
            stack.push(i);
        } else {
            stack.pop();
            if (stack.empty()) {
                stack.push(i);
            } else {
                ret = std::max(ret, i - stack.top());
            }
        }
    }

    return ret;
}

int main() {
    assert(longestValidParentheses("(()") == 2);
    assert(longestValidParentheses(")()())") == 4);
    assert(longestValidParentheses("") == 0);
    assert(longestValidParentheses("()(()") == 2);
    assert(longestValidParentheses("(((())))") == 8);
    assert(longestValidParentheses("()(())") == 6);
    return 0;
}
