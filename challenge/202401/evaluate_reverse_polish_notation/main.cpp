#include <cassert>
#include <vector>
#include <string>
#include <stack>

int evalRPN(const std::vector<std::string> &tokens) {
    const auto isOpCode = [](const std::string &s) -> bool { return s == "+" || s == "-" || s == "*" || s == "/"; };

    std::stack<int> stack;
    for (const std::string &token : tokens) {
        if (isOpCode(token)) {
            int num2 = stack.top();
            stack.pop();
            int num1 = stack.top();
            stack.pop();

            switch (token[0]) {
            case '+':
                stack.push(num1 + num2);
                break;
            case '-':
                stack.push(num1 - num2);
                break;
            case '*':
                stack.push(num1 * num2);
                break;
            case '/':
                stack.push(num1 / num2);
                break;
            default:
                assert(!"never reach here");
                break;
            }

        } else {
            int num = std::stoi(token);
            stack.push(num);
        }
    }

    return stack.top();
}

int main() {
    {
        std::vector<std::string> tokens{"2", "1", "+", "3", "*"};
        int ret = evalRPN(tokens);
        assert(ret == 9);
    }
    {
        std::vector<std::string> tokens{"4", "13", "5", "/", "+"};
        int ret = evalRPN(tokens);
        assert(ret == 6);
    }
    {
        std::vector<std::string> tokens{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
        int ret = evalRPN(tokens);
        assert(ret == 22);
    }
    return 0;
}
