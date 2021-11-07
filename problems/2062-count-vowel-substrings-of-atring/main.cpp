#include <cassert>
#include <string>
#include <set>

int countVowelSubstrings(const std::string &word) {
    int ret = 0;
    int len = word.size();
    for (int i = 0; i < len - 4; ++i) {
        std::set<int> s;
        for (int j = i; j < len; ++j) {
            char c = word[j];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                s.insert(c);
                if (s.size() >= 5) {
                    ++ret;
                }
            } else {
                break;
            }
        }
    }

    return ret;
}

int main() {
    assert(countVowelSubstrings("aeiouu") == 2);
    assert(countVowelSubstrings("unicornarihan") == 0);
    assert(countVowelSubstrings("cuaieuouac") == 7);
    assert(countVowelSubstrings("bbaeixoubb") == 0);
    assert(countVowelSubstrings("duuebuaeeeeeeuaoeiueaoui") == 81);
    return 0;
}