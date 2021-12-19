#include <cassert>
#include <string>
#include <vector>

std::string decodeString(const std::string &s) {
    std::vector<int> num_stack;
    std::vector<std::string> str_stack;

    int num = 0;
    std::string str;
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            num = 10 * num + c - '0';
        } else if (c == '[') {
            str_stack.push_back(str);
            num_stack.push_back(num);
            str = "";
            num = 0;
        } else if (c == ']') {
            int last_num = num_stack.back();
            num_stack.pop_back();

            std::string tmp = str;
            for (int i = 1; i < last_num; ++i) {
                tmp += str;
            }

            str = str_stack.back();
            str_stack.pop_back();
            str += tmp;
        } else {
            str.push_back(c);
        }
    }

    return str;
}

int main() {
    assert(decodeString("3[a]2[bc]") == "aaabcbc");
    assert(decodeString("3[a2[c]]") == "accaccacc");
    assert(decodeString("2[abc]3[cd]ef") == "abcabccdcdcdef");
    assert(decodeString("abc3[cd]xyz") == "abccdcdcdxyz");
    assert(decodeString("3[abc]") == "abcabcabc");
    return 0;
}