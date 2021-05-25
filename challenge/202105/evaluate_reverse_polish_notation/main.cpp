#include <cassert>
#include <vector>
#include <string>
#include <stack>

int evalRPN(const std::vector<std::string> &tokens) {
    std::stack<int> s;
    for (const auto &token : tokens) {
        if (token == "+") {
            int right = s.top();
            s.pop();
            int left = s.top();
            s.pop();

            s.push(left + right);
        } else if (token == "-") {
            int right = s.top();
            s.pop();
            int left = s.top();
            s.pop();

            s.push(left - right);
        } else if (token == "*") {
            int right = s.top();
            s.pop();
            int left = s.top();
            s.pop();

            s.push(left * right);
        } else if (token == "/") {
            int right = s.top();
            s.pop();
            int left = s.top();
            s.pop();

            s.push(left / right);
        } else {
            s.push(std::stoi(token));
        }
    }

    return s.top();
}

int main() {
    {
        std::vector<std::string> tokens{"2", "1", "+", "3", "*"};
        assert(evalRPN(tokens) == 9);
    }
    {
        std::vector<std::string> tokens{"4", "13", "5", "/", "+"};
        assert(evalRPN(tokens) == 6);
    }
    {
        std::vector<std::string> tokens{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
        assert(evalRPN(tokens) == 22);
    }
    return 0;
}
