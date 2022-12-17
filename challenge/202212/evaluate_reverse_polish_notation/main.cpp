#include <cassert>
#include <vector>
#include <string>
#include <cstdint>

int evalRPN(const std::vector<std::string> &tokens) {
    std::vector<int64_t> stack;
    for (const auto &token : tokens) {
        if (token == "+") {
            int64_t op2 = stack.back();
            stack.pop_back();
            int64_t op1 = stack.back();
            stack.pop_back();

            stack.push_back(op1 + op2);
        } else if (token == "-") {
            int64_t op2 = stack.back();
            stack.pop_back();
            int64_t op1 = stack.back();
            stack.pop_back();

            stack.push_back(op1 - op2);
        } else if (token == "*") {
            int64_t op2 = stack.back();
            stack.pop_back();
            int64_t op1 = stack.back();
            stack.pop_back();

            stack.push_back(op1 * op2);
        } else if (token == "/") {
            int64_t op2 = stack.back();
            stack.pop_back();
            int64_t op1 = stack.back();
            stack.pop_back();

            stack.push_back(op1 / op2);
        } else {
            int64_t num = std::stoi(token);
            stack.push_back(num);
        }
    }

    return stack.front();
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
