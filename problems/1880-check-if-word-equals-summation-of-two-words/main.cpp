#include <cassert>
#include <string>

bool isSumEqual(const std::string &firstWord, const std::string &secondWord, const std::string &targetWord) {
    const auto f = [](const std::string &s) -> int {
        int ret = 0;
        for (char c : s) {
            ret = 10 * ret + c - 'a';
        }

        return ret;
    };

    return f(firstWord) + f(secondWord) == f(targetWord);
}

int main() {
    assert(isSumEqual("acb", "cba", "cdb"));
    assert(!isSumEqual("aaa", "a", "aab"));
    assert(isSumEqual("aaa", "a", "aaaa"));
    return 0;
}
