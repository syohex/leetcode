#include <cassert>
#include <string>
#include <stack>

std::string decodeString(const std::string &s) {
    std::stack<int> repeat_stack;
    std::stack<std::string> string_stack;
    std::string ret;
    std::string buf;

    int repeat = 0;
    for (auto c : s) {
        if (c >= 'a' && c <= 'z') {
            if (repeat_stack.empty()) {
                ret.push_back(c);
            } else {
                buf += c;
            }
        } else if (c >= '0' && c <= '9') {
            repeat = 10 * repeat + (c - '0');
        } else if (c == '[') {
            if (!repeat_stack.empty()) {
                string_stack.push(buf);
                buf = "";
            }

            repeat_stack.push(repeat);
            repeat = 0;
        } else if (c == ']') {
            int num = repeat_stack.top();
            repeat_stack.pop();

            std::string tmp = buf;
            for (int i = 0; i < num - 1; ++i) {
                tmp += buf;
            }

            if (string_stack.empty()) {
                ret += tmp;
                buf = "";
            } else {
                buf = string_stack.top() + tmp;
                string_stack.pop();
            }
        }
    }
    return ret;
}

int main() {
    assert(decodeString("3[a]2[bc]") == "aaabcbc");
    assert(decodeString("3[a2[c]]") == "accaccacc");
    assert(decodeString("2[abc]3[cd]ef") == "abcabccdcdcdef");
    assert(decodeString("abc3[cd]xyz") == "abccdcdcdxyz");
    assert(decodeString("abcde") == "abcde");
    assert(decodeString("1[abcde]") == "abcde");
    return 0;
}
