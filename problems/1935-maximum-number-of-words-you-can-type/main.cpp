#include <cassert>
#include <string>
#include <vector>

int canByTypedWords(const std::string &text, const std::string &brokenLetters) {
    std::vector<bool> v(26, false);
    for (char c : brokenLetters) {
        v[c - 'a'] = true;
    }

    int ret = 0;
    bool ok = true;
    for (size_t i = 0; i < text.size(); ++i) {
        char c = text[i];
        if (c >= 'a' && c <= 'z') {
            if (v[c - 'a']) {
                ok = false;
            }
        } else {
            if (ok) {
                ++ret;
            }

            ok = true;
        }
    }

    if (ok) {
        ++ret;
    }

    return ret;
}

int main() {
    assert(canByTypedWords("hello world", "ad") == 1);
    assert(canByTypedWords("leet code", "lt") == 1);
    assert(canByTypedWords("leet code", "e") == 0);
    return 0;
}