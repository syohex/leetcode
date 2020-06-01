#include <cassert>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

bool isValid(const std::string &s) {
    std::vector<char> v;
    std::map<char, char> m{
        {')', '('},
        {'}', '{'},
        {']', '['},
    };

    for (const auto c : s) {
        switch (c) {
        case ')':
        case '}':
        case ']': {
            const auto it = std::find(v.begin(), v.end(), m[c]);
            if (it == v.end()) {
                return false;
            }

            while (!v.empty()) {
                char tmp = v.back();
                v.pop_back();
                if (tmp == '{' || tmp == '[' || tmp == '(') {
                    break;
                }
            }
            break;
        }
        default:
            v.push_back(c);
            break;
        }
    }

    return v.empty();
}

int main() {
    assert(isValid("()"));
    assert(isValid("()[]{}"));
    assert(!isValid("(]"));
    assert(!isValid("([)]"));
    assert(isValid("{[]}"));
    assert(!isValid("([)"));
    assert(!isValid("(])"));
    return 0;
}