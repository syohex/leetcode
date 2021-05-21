#include <cassert>
#include <vector>
#include <string>
#include <set>

std::vector<std::string> findAndReplacePattern(std::vector<std::string> &words, std::string &pattern) {
    const auto f = [](std::string &str) {
        char c = 'A';
        for (size_t i = 0; i < str.size(); ++i) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                continue;
            }

            for (size_t j = i + 1; j < str.size(); ++j) {
                if (str[i] == str[j]) {
                    str[j] = c;
                }
            }

            str[i] = c;
            ++c;
        }
    };

    f(pattern);

    std::vector<std::string> ret;
    std::string orig;
    for (auto &word : words) {
        orig = word;
        f(word);
        if (word == pattern) {
            ret.push_back(orig);
        }
    }

    return ret;
}

void check(const std::vector<std::string> &got, const std::vector<std::string> &expected) {
    assert((std::set<std::string>(got.begin(), got.end()) == std::set<std::string>(expected.begin(), expected.end())));
}

int main() {
    {
        std::vector<std::string> words{"abc", "deq", "mee", "aqq", "dkd", "ccc"};
        std::vector<std::string> expected{"mee", "aqq"};
        std::string pattern("abb");
        auto ret = findAndReplacePattern(words, pattern);
        check(ret, expected);
    }
    {
        std::vector<std::string> words{"a", "b", "c"};
        std::vector<std::string> expected{"a", "b", "c"};
        std::string pattern("a");
        auto ret = findAndReplacePattern(words, pattern);
        check(ret, expected);
    }
    return 0;
}
