#include <cassert>
#include <string>
#include <vector>

std::string removeOuterParentheses(const std::string &S) {
    std::string ret;
    size_t outMost = 0;
    for (size_t i = 1; i < S.size(); ++i) {
        if (S[i] == ')') {
            for (int j = static_cast<int>(i) - 1, skip = 0; j >= static_cast<int>(outMost); --j) {
                if (S[j] == '(') {
                    if (skip == 0) {
                        if (j != static_cast<int>(outMost)) {
                            break;
                        }

                        ret += S.substr(outMost + 1, i - (outMost + 1));
                        outMost = i + 1;
                        break;
                    }

                    --skip;
                } else if (S[j] == ')') {
                    ++skip;
                }
            }
        }
    }

    return ret;
}

int main() {
    assert(removeOuterParentheses("(()())(())") == "()()()");
    assert(removeOuterParentheses("(()())(())(()(()))") == "()()()()(())");
    assert(removeOuterParentheses("()()") == "");
    return 0;
}
