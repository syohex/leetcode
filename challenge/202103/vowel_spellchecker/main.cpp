#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cctype>

std::vector<std::string> spellchecker(const std::vector<std::string> &wordlist, const std::vector<std::string> &queries) {
    const auto isVowel = [](char c) -> bool { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; };

    std::set<std::string> wordSet;
    std::map<std::string, size_t> lowerWordMap;
    std::vector<std::string> lowerWords;
    for (size_t i = 0; i < wordlist.size(); ++i) {
        wordSet.insert(wordlist[i]);

        std::string lower;
        for (const char c : wordlist[i]) {
            lower.push_back(std::tolower(static_cast<int>(c)));
        }

        lowerWords.push_back(lower);
        if (lowerWordMap.find(lower) == lowerWordMap.end()) {
            lowerWordMap[lower] = i;
        }
    }

    std::vector<std::string> lowerQueries;
    for (size_t i = 0; i < queries.size(); ++i) {
        std::string lower;
        for (const char c : queries[i]) {
            lower.push_back(std::tolower(static_cast<int>(c)));
        }

        lowerQueries.push_back(lower);
    }

    std::vector<std::string> ret;
    for (size_t i = 0; i < queries.size(); ++i) {
        if (wordSet.find(queries[i]) != wordSet.end()) {
            ret.push_back(queries[i]);
            continue;
        }

        auto it = lowerWordMap.find(lowerQueries[i]);
        if (it != lowerWordMap.end()) {
            ret.push_back(wordlist[it->second]);
            continue;
        }

        for (const auto &it2 : lowerWordMap) {
            if (lowerQueries[i].size() != it2.first.size()) {
                continue;
            }
        }

        for (size_t j = 0; j < lowerWords.size(); ++j) {
            if (lowerQueries[i].size() != lowerWords[j].size()) {
                continue;
            }

            bool ok = true;
            for (size_t k = 0; k < lowerQueries[i].size(); ++k) {
                char c1 = lowerQueries[i][k];
                char c2 = lowerWords[j][k];
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
