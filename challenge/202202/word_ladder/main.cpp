#include <cassert>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

int ladderLength(const std::string &beginWord, const std::string &endWord, const std::vector<std::string> &wordList) {
    std::string base = beginWord;

    std::map<std::string, std::set<std::string>> graph;
    for (const auto &w : wordList) {
        for (size_t i = 0; i < w.size(); ++i) {
            std::string key = w;
            key[i] = '?';
            graph[key].insert(w);
        }
    }

    struct Data {
        std::string word;
        int count;
    };

    const auto cmp = [](const Data &a, const Data &b) { return a.count > b.count; };

    std::priority_queue<Data, std::vector<Data>, decltype(cmp)> q(cmp);
    q.push({beginWord, 1});

    std::set<std::string> checked;

    while (!q.empty()) {
        Data d = q.top();
        q.pop();

        if (d.word == endWord) {
            return d.count;
        }

        for (size_t i = 0; i < d.word.size(); ++i) {
            std::string key = d.word;
            key[i] = '?';

            if (graph.find(key) == graph.end()) {
                continue;
            }

            for (const auto &next : graph[key]) {
                if (checked.find(next) != checked.end()) {
                    continue;
                }

                checked.insert(next);
                q.push({next, d.count + 1});
            }
        }
    }

    return 0;
}

int main() {
    {
        std::string beginWord("hit");
        std::string endWord("cog");
        std::vector<std::string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
        assert(ladderLength(beginWord, endWord, wordList) == 5);
    }
    {
        std::string beginword("hit");
        std::string endword("cog");
        std::vector<std::string> wordlist{"hot", "dot", "dog", "lot", "log"};
        assert(ladderLength(beginword, endword, wordlist) == 0);
    }
    {
        std::string beginword("qa");
        std::string endword("sq");
        std::vector<std::string> wordlist{
            "si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le", "av", "sm", "ar", "ci", "ca",
            "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn", "ya", "cr", "po", "fe", "ho", "ma", "re", "or", "rn", "au",
            "ur", "rh", "sr", "tc", "lt", "lo", "as", "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb", "sh", "co", "ga",
            "li", "ha", "hz", "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an", "me", "mo", "na", "la", "st", "er",
            "sc", "ne", "mn", "mi", "am", "ex", "pt", "io", "be", "fm", "ta", "tb", "ni", "mr", "pa", "he", "lr", "sq", "ye"};
        assert(ladderLength(beginword, endword, wordlist) == 5);
    }
    return 0;
}
