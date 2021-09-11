#include <cassert>
#include <string>
#include <cstdint>
#include <vector>
#include <stack>

int calculate(const std::string& s) {
    struct Term {
        bool is_op;
        union {
            std::int64_t num;
            char op;
        } u;

        explicit Term(std::int64_t num) : is_op(false) {
            u.num = num;
        }
        explicit Term(char op) : is_op(true) {
            u.op = op;
        }
    };

    std::vector<Term> rpn;
    std::stack<char> ops;

    int len = s.size();
    int pos = 0;
    while (pos < len) {
        while (pos < len && s[pos] == ' ') {
            ++pos;
        }

        if (pos >= len) {
            continue;
        }

        if (s[pos] == '+' || s[pos] == '-') {
            if (!ops.empty() && (ops.top() == '+' || ops.top() == '-')) {
                char op = ops.top();
                ops.pop();
                rpn.push_back(Term(op));
            }

            ops.push(s[pos]);
            ++pos;
            continue;
        } else if (s[pos] == '(') {
            ops.push(s[pos]);
            ++pos;
            continue;
        } else if (s[pos] == ')') {
            while (!ops.empty()) {
                char op = ops.top();
                ops.pop();
                if (op == '(') {
                    break;
                }

                rpn.push_back(Term(op));
            }

            ++pos;
            continue;
        }

        std::int64_t num = s[pos] - '0';
        ++pos;
        while (pos < len && s[pos] >= '0' && s[pos] <= '9') {
            num = 10 * num + s[pos] - '0';
            ++pos;
        }

        rpn.push_back(Term(num));
    }

    while (!ops.empty()) {
        char op = ops.top();
        ops.pop();
        rpn.push_back(Term(op));
    }

    std::stack<std::int64_t> nums;
    for (const auto& term : rpn) {
        if (term.is_op) {
            if (term.u.op == '+') {
                auto num2 = nums.top();
                nums.pop();
                auto num1 = nums.top();
                nums.pop();
                nums.push(num1 + num2);
            } else {
                auto num2 = nums.top();
                nums.pop();
                if (nums.empty()) {
                    nums.push(-1 * num2);
                    continue;
                }

                auto num1 = nums.top();
                nums.pop();
                nums.push(num1 - num2);
            }
        } else {
            nums.push(term.u.num);
        }
    }

    return static_cast<int>(nums.top());
}

int main() {
    {
        std::string s("1 + 1");
        assert(calculate(s) == 2);
    }
    {
        std::string s(" 2-1 + 2 ");
        assert(calculate(s) == 3);
    }
    {
        std::string s("(1+(4+5+2)-3)+(6+8)");
        assert(calculate(s) == 23);
    }
    {
        std::string s("(1+(4+5+2)-3)+(6-8)");
        assert(calculate(s) == 7);
    }
    {
        std::string s("- (3 + (4 + 5))");
        assert(calculate(s) == -12);
    }
    return 0;
}