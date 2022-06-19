#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::vector<std::string>> suggestedProducts(const std::vector<std::string> &products, const std::string &searchWord) {
    struct Trie {
        std::vector<Trie *> table;
        std::vector<std::string> candidates;

        Trie() : table(26, nullptr) {
        }
    };

    Trie trie;
    for (const auto &product : products) {
        Trie *cur = &trie;
        for (char c : product) {
            size_t index = c - 'a';
            if (cur->table[index] == nullptr) {
                cur->table[index] = new Trie();
            }

            cur = cur->table[index];
            cur->candidates.push_back(product);
        }
    }

    std::vector<std::vector<std::string>> ret;
    Trie *cur = &trie;
    for (char c : searchWord) {
        size_t index = c - 'a';
        if (cur == nullptr || cur->table[index] == nullptr) {
            ret.push_back({});
            cur = nullptr;
            continue;
        }

        cur = cur->table[index];
        auto candidates = cur->candidates;
        std::sort(candidates.begin(), candidates.end());

        size_t limit = std::min(static_cast<size_t>(3), candidates.size());
        candidates.resize(limit);

        ret.push_back(candidates);
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> products{"mobile", "mouse", "moneypot", "monitor", "mousepad"};
        std::string searchWord = "mouse";

        std::vector<std::vector<std::string>> expected{
            {"mobile", "moneypot", "monitor"},
            {"mobile", "moneypot", "monitor"},
            {"mouse", "mousepad"},
            {"mouse", "mousepad"},
            {"mouse", "mousepad"},
        };

        auto ret = suggestedProducts(products, searchWord);
        assert(ret == expected);
    }
    {
        std::vector<std::string> products{"havana"};
        std::string searchWord = "havana";

        std::vector<std::vector<std::string>> expected{
            {"havana"}, {"havana"}, {"havana"}, {"havana"}, {"havana"}, {"havana"},
        };

        auto ret = suggestedProducts(products, searchWord);
        assert(ret == expected);
    }
    {
        std::vector<std::string> products{"bags", "baggage", "banner", "box", "cloths"};
        std::string searchWord = "bags";

        std::vector<std::vector<std::string>> expected{
            {"baggage", "bags", "banner"},
            {"baggage", "bags", "banner"},
            {"baggage", "bags"},
            {"bags"},
        };

        auto ret = suggestedProducts(products, searchWord);
        assert(ret == expected);
    }
    {
        std::vector<std::string> products{"havana"};
        std::string searchWord = "tatiana";

        std::vector<std::vector<std::string>> expected{
            {}, {}, {}, {}, {}, {}, {},
        };

        auto ret = suggestedProducts(products, searchWord);
        assert(ret == expected);
    }
    return 0;
}