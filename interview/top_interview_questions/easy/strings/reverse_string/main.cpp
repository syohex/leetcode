#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

void reverseString(std::vector<char> &s) {
    int start = 0;
    int end = static_cast<int>(s.size() - 1);

    while (start <= end) {
        std::swap(s[start], s[end]);

        ++start;
        --end;
    }
}

int main() {
    {
        std::string tmp("hello");
        std::vector<char> s(tmp.begin(), tmp.end());
        reverseString(s);

        assert((s == std::vector<char>{'o', 'l', 'l', 'e', 'h'}));
    }
    {
        std::string tmp("Hannah");
        std::vector<char> s(tmp.begin(), tmp.end());
        reverseString(s);

        assert((s == std::vector<char>{'h', 'a', 'n', 'n', 'a', 'H'}));
    }
    return 0;
}
