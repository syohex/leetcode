#include <cassert>
#include <string>

char kthCharacter(int k) {
    std::string s;
    s.push_back('a');

    std::size_t n = k;
    while (s.size() < n) {
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            s.push_back(s[i] == 'z' ? 'a' : s[i] + 1);
        }
    }

    return s[k - 1];
}

int main() {
    assert(kthCharacter(5) == 'b');
    assert(kthCharacter(10) == 'c');
    return 0;
}
