#include <cassert>
#include <vector>
#include <functional>
#include <string>
#include <cstdio>

void reverseString(std::vector<char> &s) {
    if (s.empty()) {
        return;
    }

    std::function<void(std::vector<char> & v, size_t i, char prev)> f;
    f = [&f](std::vector<char> &v, size_t i, char prev) {
        if (v.size() == i) {
            v[v.size() - i] = prev;
            return;
        }

        f(v, i + 1, v[i]);

        if (i != 0) {
            v[v.size() - i] = prev;
        }
    };

    f(s, 0, 0);
}

int main() {
    {
        std::string s("hello");
        std::vector<char> v(s.begin(), s.end());
        reverseString(v);
        s.assign(v.begin(), v.end());
        assert(s == "olleh");
    }
    {
        std::string s("Hannah");
        std::vector<char> v(s.begin(), s.end());
        reverseString(v);
        s.assign(v.begin(), v.end());
        assert(s == "hannaH");
    }
    return 0;
}
