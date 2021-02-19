#include <cassert>
#include <vector>
#include <string>
#include <stack>

std::string minRemoveToMakeValid(const std::string &s) {
    struct Data {
        char c = 0;
        size_t pos = 0;
    };

    size_t pos = 0;
    std::vector<Data> v(s.size());
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            v[pos].c = '(';
            v[pos].pos = i;
            ++pos;
        } else if (s[i] == ')') {
            if (pos >= 1 && v[pos - 1].c == '(') {
                --pos;
            } else {
                v[pos].c = ')';
                v[pos].pos = i;
                ++pos;
            }
        }
    }

    if (pos == 0) {
        return s;
    }

    size_t limit = pos;
    pos = 0;
    std::string ret;
    bool has_content = true;
    for (size_t i = 0; i < s.size(); ++i) {
        if (has_content && i == v[pos].pos) {
            ++pos;
            if (pos >= limit) {
                has_content = false;
            }
        } else {
            ret.push_back(s[i]);
        }
    }

    return ret;
}

int main() {
    assert(minRemoveToMakeValid("lee(t(c)o)de)") == "lee(t(c)o)de");
    assert(minRemoveToMakeValid("a)b(c)d") == "ab(c)d");
    assert(minRemoveToMakeValid("))((") == "");
    assert(minRemoveToMakeValid("(a(b(c)d)") == "a(b(c)d)");
    assert(minRemoveToMakeValid("abc") == "abc");
    return 0;
}
