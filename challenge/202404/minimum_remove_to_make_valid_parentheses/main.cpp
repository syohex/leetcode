#include <cassert>
#include <string>
#include <vector>

std::string minRemoveToMakeValid(const std::string &s) {
    std::vector<std::pair<char, size_t>> q;
    for (size_t i = 0; i < s.size(); ++i) {
        switch (s[i]) {
        case '(':
            q.push_back({s[i], i});
            break;
        case ')':
            if (!q.empty() && q.back().first == '(') {
                q.pop_back();
            } else {
                q.push_back({s[i], i});
            }
            break;
        default:
            break;
        }
    }

    std::string ret;
    size_t j = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (j < q.size() && i == q[j].second) {
            ++j;
            continue;
        }

        ret.push_back(s[i]);
    }

    return ret;
}

int main() {
    assert(minRemoveToMakeValid("lee(t(c)o)de)") == "lee(t(c)o)de");
    assert(minRemoveToMakeValid("a)b(c)d") == "ab(c)d");
    assert(minRemoveToMakeValid("))((") == "");
    assert(minRemoveToMakeValid("abc") == "abc");
    return 0;
}
