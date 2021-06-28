#include <cassert>
#include <string>
#include <stack>

std::string removeDuplicates(const std::string &s) {
    int len = s.size();
    std::stack<char> stack;
    stack.push(s[0]);
    for (int i = 1; i < len; ++i) {
        if (!stack.empty() && stack.top() == s[i]) {
            stack.pop();
        } else {
            stack.push(s[i]);
        }
    }

    len = stack.size();
    std::string ret(len, 0);
    for (int i = len - 1; i >= 0; --i) {
        ret[i] = stack.top();
        stack.pop();
    }

    return ret;
}

int main() {
    assert(removeDuplicates("abbaca") == "ca");
    assert(removeDuplicates("azxxzy") == "ay");
    assert(removeDuplicates("aaaaaaaaa") == "a");
    assert(removeDuplicates("baaaaaa") == "b");
    assert(removeDuplicates("baaaaaac") == "bc");
    return 0;
}