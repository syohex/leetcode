#include <cassert>
#include <string>
#include <algorithm>

int isPrefixOfWord(const std::string &sentence, const std::string &searchWord) {
    size_t pos = 0;
    while (sentence[pos] == ' ') {
        ++pos;
    }

    int word = 0;
    for (size_t i = pos; i < sentence.size();) {
        if (sentence[i] == ' ') {
            ++word;
            if (i - pos >= searchWord.size()) {
                bool match = std::equal(sentence.begin() + pos, sentence.begin() + pos + searchWord.size(), searchWord.begin(),
                                        searchWord.end());
                if (match) {
                    return word;
                }
            }

            while (sentence[i] == ' ') {
                ++i;
                if (i >= sentence.size()) {
                    return -1;
                }
            }

            pos = i;
        }

        ++i;
    }

    if (sentence.size() - pos >= searchWord.size()) {
        bool match =
            std::equal(sentence.begin() + pos, sentence.begin() + pos + searchWord.size(), searchWord.begin(), searchWord.end());
        if (match) {
            return word + 1;
        }
    }

    return -1;
}

int main() {
    int ret = isPrefixOfWord("i love eating burger", "burg");
    assert(ret == 4);

    ret = isPrefixOfWord("this problem is an easy problem", "pro");
    assert(ret == 2);

    ret = isPrefixOfWord("i am tired", "you");
    assert(ret == -1);

    ret = isPrefixOfWord("i use triple pillow", "pill");
    assert(ret == 4);

    ret = isPrefixOfWord("hello from the other side", "they");
    assert(ret == -1);

    ret = isPrefixOfWord("hello from the other side", "side");
    assert(ret == 5);

    ret = isPrefixOfWord("hello from the other side               ", "side");
    assert(ret == 5);

    ret = isPrefixOfWord("             hello from the other side               ", "side");
    assert(ret == 5);

    return 0;
}
