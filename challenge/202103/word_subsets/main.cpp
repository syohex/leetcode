#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

std::vector<std::string> wordSets(const std::vector<std::string> &A, const std::vector<std::string> &B) {
    const auto f = [](const std::string &str) -> std::map<char, int> {
        std::map<char, int> m;
        for (char c : str) {
            ++m[c];
        }

        return m;
    };

    std::map<char, int> subset_table;
    for (const auto &subset : B) {
        auto tmp = f(subset);
        for (const auto &it : tmp) {
            subset_table[it.first] = std::max(subset_table[it.first], it.second);
        }
    }

    std::vector<std::string> ret;
    for (const auto &word : A) {
        auto tmp = f(word);

        bool ok = true;
        for (const auto &it : subset_table) {
            if (it.second > tmp[it.first]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ret.push_back(word);
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> words{"amazon", "apple", "facebook", "google", "leetcode"};
        std::vector<std::string> subs{"e", "o"};
        std::vector<std::string> expected{"facebook", "google", "leetcode"};
        auto ret = wordSets(words, subs);
        assert(ret == expected);
    }
    {
        std::vector<std::string> words{"amazon", "apple", "facebook", "google", "leetcode"};
        std::vector<std::string> subs{"l", "e"};
        std::vector<std::string> expected{"apple", "google", "leetcode"};
        auto ret = wordSets(words, subs);
        assert(ret == expected);
    }
    {
        std::vector<std::string> words{"amazon", "apple", "facebook", "google", "leetcode"};
        std::vector<std::string> subs{"e", "oo"};
        std::vector<std::string> expected{"facebook", "google"};
        auto ret = wordSets(words, subs);
        assert(ret == expected);
    }
    {
        std::vector<std::string> words{"amazon", "apple", "facebook", "google", "leetcode"};
        std::vector<std::string> subs{"lo", "eo"};
        std::vector<std::string> expected{"google", "leetcode"};
        auto ret = wordSets(words, subs);
        assert(ret == expected);
    }
    {
        std::vector<std::string> words{"amazon", "apple", "facebook", "google", "leetcode"};
        std::vector<std::string> subs{"ec", "oc", "ceo"};
        std::vector<std::string> expected{"facebook", "leetcode"};
        auto ret = wordSets(words, subs);
        assert(ret == expected);
    }
    return 0;
}
