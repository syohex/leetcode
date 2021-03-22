#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cctype>

std::vector<std::string> spellchecker(const std::vector<std::string> &wordlist, const std::vector<std::string> &queries) {
    const auto isVowel = [](char c) -> bool { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; };

    std::set<std::string> wordSet;
    std::map<std::string, size_t> lowerWordMap, nonVowelWordMap;
    std::vector<std::string> lowerWords;
    for (size_t i = 0; i < wordlist.size(); ++i) {
        wordSet.insert(wordlist[i]);

        std::string lower, nonVowel;
        for (const char c : wordlist[i]) {
            char lc = std::tolower(c);
            lower.push_back(lc);
            nonVowel.push_back(isVowel(lc) ? '9' : lc);
        }

        lowerWords.push_back(lower);
        if (lowerWordMap.find(lower) == lowerWordMap.end()) {
            lowerWordMap[lower] = i;
        }
        if (nonVowelWordMap.find(nonVowel) == nonVowelWordMap.end()) {
            nonVowelWordMap[nonVowel] = i;
        }
    }

    std::vector<std::string> lowerQueries, nonVowelQueries;
    for (size_t i = 0; i < queries.size(); ++i) {
        std::string lower, nonVowel;
        for (const char c : queries[i]) {
            char lc = std::tolower(c);
            lower.push_back(lc);
            nonVowel.push_back(isVowel(lc) ? '9' : lc);
        }

        lowerQueries.push_back(lower);
        nonVowelQueries.push_back(nonVowel);
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

        auto it2 = nonVowelWordMap.find(nonVowelQueries[i]);
        if (it2 != nonVowelWordMap.end()) {
            ret.push_back(wordlist[it2->second]);
            continue;
        }

        ret.push_back("");
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
