#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> findOcurrences(const std::string &text, const std::string &first, const std::string &second) {
    enum State {
        kNone,
        kFirstMatched,
    };

    std::vector<std::string> ret;
    size_t i = 0;
    State state = kNone;
    const std::string *searchWord = &first;
    while (i < text.size()) {
        while (text[i] == ' ' && i < text.size()) {
            ++i;
        }

        size_t orig = i;
        if (text[i] == searchWord->at(0)) {
            ++i;
            bool ok = true;
            for (size_t j = 1; j < searchWord->size() && i < text.size(); ++j) {
                if (text[i++] != searchWord->at(j)) {
                    ok = false;
                    break;
                }
            }
            if (i >= text.size()) {
                break;
            }
            if (ok && text[i] == ' ') {
                if (state == kFirstMatched) {
                    while (text[i] == ' ' && i < text.size()) {
                        ++i;
                    }

                    size_t pos = i;
                    size_t j = i;
                    while (text[j] != ' ' && j < text.size()) {
                        ++j;
                    }

                    ret.push_back(text.substr(pos, j - pos));

                    state = kNone;
                    searchWord = &first;
                    continue;
                }

                state = kFirstMatched;
                searchWord = &second;
                continue;
            }
        }

        searchWord = &first;
        if (state == kFirstMatched) {
            i = orig;
            state = kNone;
            continue;
        }

        state = kNone;
        while (text[i] != ' ' && i < text.size()) {
            ++i;
        }
    }

    return ret;
}

int main() {
    {
        auto ret = findOcurrences("", "a", "good");
        assert(ret.size() == 0);
    }
    {
        std::string text = "alice is a good girl she is a good student";
        auto ret = findOcurrences(text, "a", "good");
        assert(ret.size() == 2);
        assert(ret[0] == "girl");
        assert(ret[1] == "student");
    }
    {
        std::string text = "we will we will rock you";
        auto ret = findOcurrences(text, "we", "will");
        assert(ret.size() == 2);
        assert(ret[0] == "we");
        assert(ret[1] == "rock");
    }
    {
        std::string text = "first second third";
        auto ret = findOcurrences(text, "first", "second");
        assert(ret.size() == 1);
        assert(ret[0] == "third");
    }
    {
        std::string text = "first secondly third";
        auto ret = findOcurrences(text, "first", "second");
        assert(ret.size() == 0);
    }
    {
        std::string text = "obo jvezipre obo jnvavldde jvezipre jvezipre jnvavldde jvezipre jvezipre jvezipre y jnvavldde "
                           "jnvavldde obo jnvavldde jnvavldde obo jnvavldde jnvavldde jvezipre";
        auto ret = findOcurrences(text, "jnvavldde", "y");
        assert(ret.size() == 0);
    }
    {
        std::string text = "jkypmsxd jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa kcyxdfnoa jkypmsxd kcyxdfnoa";
        auto ret = findOcurrences(text, "kcyxdfnoa", "jkypmsxd");
        assert((ret == std::vector<std::string>{"kcyxdfnoa", "kcyxdfnoa", "kcyxdfnoa"}));
    }

    return 0;
}
