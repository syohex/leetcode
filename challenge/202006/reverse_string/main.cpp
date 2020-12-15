#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

void reverseString(std::vector<char> &s) {
    int left = 0;
    int right = static_cast<int>(s.size()) - 1;

    while (left < right) {
        std::swap(s[left], s[right]);
        ++left;
        --right;
    }
}

int main() {
    {
        std::string tmp("hello");
        std::vector<char> v(tmp.begin(), tmp.end());
        reverseString(v);

        std::reverse(tmp.begin(), tmp.end());

        std::string got(v.begin(), v.end());
        assert(got == tmp);
    }
    {
        std::string tmp("Hannah");
        std::vector<char> v(tmp.begin(), tmp.end());
        reverseString(v);

        std::reverse(tmp.begin(), tmp.end());

        std::string got(v.begin(), v.end());
        assert(got == tmp);
    }
    {
        std::string tmp("a");
        std::vector<char> v(tmp.begin(), tmp.end());
        reverseString(v);

        std::reverse(tmp.begin(), tmp.end());

        std::string got(v.begin(), v.end());
        assert(got == tmp);
    }
    {
        std::string tmp("");
        std::vector<char> v(tmp.begin(), tmp.end());
        reverseString(v);

        std::reverse(tmp.begin(), tmp.end());

        std::string got(v.begin(), v.end());
        assert(got == tmp);
    }
    return 0;
}
