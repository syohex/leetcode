#include <cassert>
#include <vector>
#include <string>
#include <cctype>

std::vector<std::string> spellchecker(const std::vector<std::string> &wordlist, const std::vector<std::string> &queries) {
    const auto isVowel = [](char c) -> bool { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; };

    std::vector<std::string> lowerWordList, lowerQueries;
    std::string tmp;
    for (const auto &word : wordlist) {
        for (const char c : word) {
            tmp.push_back(std::tolower(static_cast<int>(c)));
        }
        lowerWordList.push_back(tmp);
        tmp.clear();
    }

    for (const auto &query : queries) {
        for (const char c : query) {
            tmp.push_back(std::tolower(static_cast<int>(c)));
        }
        lowerQueries.push_back(tmp);
        tmp.clear();
    }

    std::vector<std::string> ret;
    for (size_t i = 0; i < queries.size(); ++i) {
        for (const auto &word : wordlist) {
            if (queries[i] == word) {
                ret.push_back(word);
                goto next;
            }
        }

        for (size_t j = 0; j < lowerWordList.size(); ++j) {
            if (lowerQueries[i] == lowerWordList[j]) {
                ret.push_back(wordlist[j]);
                goto next;
            }
        }

        for (size_t j = 0; j < lowerWordList.size(); ++j) {
            if (lowerQueries[i].size() != lowerWordList[j].size()) {
                continue;
            }

            bool ok = true;
            for (size_t k = 0; k < lowerQueries[i].size(); ++k) {
                char c1 = lowerQueries[i][k];
                char c2 = lowerWordList[j][k];
                if (isVowel(c1) && isVowel(c2)) {
                    continue;
                }

                if (c1 != c2) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                ret.push_back(wordlist[j]);
                goto next;
            }
        }

        ret.push_back("");
    next:;
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> wordlist{"KiTe", "kite", "hare", "Hare"};
        std::vector<std::string> queries{"kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet", "keto"};
        std::vector<std::string> expected{"kite", "KiTe", "KiTe", "Hare", "hare", "", "", "KiTe", "", "KiTe"};
        auto ret = spellchecker(wordlist, queries);
        assert(ret == expected);
    }
    {
        std::vector<std::string> wordlist{"wg", "uo", "as", "kv", "ra", "mw", "gi", "we", "og", "zu"};
        std::vector<std::string> queries{"AS", "in", "yc", "kv", "mw", "ov", "lc", "os", "wm", "Mw"};
        std::vector<std::string> expected{"as", "", "", "kv", "mw", "", "", "as", "", "mw"};
        auto ret = spellchecker(wordlist, queries);
        assert(ret == expected);
    }
    return 0;
}
