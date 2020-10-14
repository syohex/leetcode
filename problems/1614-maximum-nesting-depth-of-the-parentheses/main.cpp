#include <cassert>
#include <string>
#include <stack>
#include <cstdio>

int maxDepth(const std::string &s) {
    std::stack<char> st;
    size_t max = 0;
    size_t depth = 0;
    for (char c : s) {
        if (c != '(' && c != ')') {
            continue;
        }

        if (c == '(') {
            ++depth;
            if (depth > max) {
                max = depth;
            }

            st.push(c);
            continue;
        }

        if (c == ')' && st.top() == '(') {
            --depth;
            st.pop();
            continue;
        }
    }

    return static_cast<int>(max);
}

int main() {
    assert(maxDepth("(1+(2*3)+((8)/4))+1") == 3);
    assert(maxDepth("(1)+((2))+(((3)))") == 3);
    assert(maxDepth("1+(2*3)/(2-1)") == 1);
    assert(maxDepth("1") == 0);
    return 0;
}
