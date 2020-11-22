#include <cassert>
#include <vector>
#include <string>

bool arrayStringsAreEqual(const std::vector<std::string> &word1, const std::vector<std::string> &word2) {
    size_t i1 = 0, s1 = 0;
    size_t i2 = 0, s2 = 0;

    while (true) {
        if (word1[i1][s1] != word2[i2][s2]) {
            return false;
        }

        ++s1;
        ++s2;

        if (s1 >= word1[i1].size()) {
            ++i1;
            s1 = 0;
        }
        if (s2 >= word2[i2].size()) {
            ++i2;
            s2 = 0;
        }

        if (i1 == word1.size() && i2 == word2.size()) {
            return true;
        } else if (i1 == word1.size() || i2 == word2.size()) {
            return false;
        }
    }
}

int main() {
    {
        std::vector<std::string> word1{"ab", "c"};
        std::vector<std::string> word2{"a", "bc"};
        assert(arrayStringsAreEqual(word1, word2));
    }
    {
        std::vector<std::string> word1{"a", "cb"};
        std::vector<std::string> word2{"ab", "c"};
        assert(!arrayStringsAreEqual(word1, word2));
    }
    {
        std::vector<std::string> word1{"abc", "d", "defg"};
        std::vector<std::string> word2{"abcddefg"};
        assert(arrayStringsAreEqual(word1, word2));
    }
    return 0;
}
