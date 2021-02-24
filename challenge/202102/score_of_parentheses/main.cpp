#include <cassert>
#include <string>
#include <cmath>
#include <vector>

int scoreOfParentheses(const std::string &S) {
    std::vector<bool> stack(S.size(), false);
    size_t pos = 0;
    int score = 0;
    for (char c : S) {
        if (c == '(') {
            stack[pos++] = true;
        } else {
            --pos;
            if (stack[pos]) {
                score += std::pow(2, pos);
            }

            for (size_t i = 0; i <= pos; ++i) {
                stack[i] = false;
            }
        }
    }

    return score;
}

int main() {
    assert(scoreOfParentheses("()") == 1);
    assert(scoreOfParentheses("(())") == 2);
    assert(scoreOfParentheses("()()") == 2);
    assert(scoreOfParentheses("(()(()))") == 6);
    return 0;
}
