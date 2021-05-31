#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::vector<std::string>> suggestedProducts(std::vector<std::string> &products, const std::string &searchWord) {
    std::sort(products.begin(), products.end());

    std::vector<std::vector<std::string>> ret;
    std::string prefix;
    for (const char c : searchWord) {
        prefix += c;

        auto pos = std::lower_bound(products.begin(), products.end(), prefix);
        size_t start = pos - products.begin();

        ret.push_back(std::vector<std::string>{});

        size_t limit = std::min(start + 3, products.size());
        for (size_t i = start; i < limit; ++i) {
            if (products[i].size() < prefix.size()) {
                break;
            }
            if (!std::equal(prefix.begin(), prefix.end(), products[i].begin())) {
                break;
            }
            ret.back().push_back(products[i]);
        }
    }
    return ret;
}

int main() {
    {
        std::vector<std::string> products{
            "mobile", "mouse", "moneypot", "monitor", "mousepad",
        };
        std::vector<std::vector<std::string>> expected{
            {"mobile", "moneypot", "monitor"},
            {"mobile", "moneypot", "monitor"},
            {"mouse", "mousepad"},
            {"mouse", "mousepad"},
            {"mouse", "mousepad"},
        };
        auto ret = suggestedProducts(products, "mouse");
        assert(ret == expected);
    }
    {
        std::vector<std::string> products{"havana"};
        std::vector<std::vector<std::string>> expected{
            {"havana"}, {"havana"}, {"havana"}, {"havana"}, {"havana"}, {"havana"},
        };
        auto ret = suggestedProducts(products, "havana");
        assert(ret == expected);
    }
    {
        std::vector<std::string> products{
            "bags", "baggage", "banner", "box", "cloths",
        };
        std::vector<std::vector<std::string>> expected{
            {"baggage", "bags", "banner"},
            {"baggage", "bags", "banner"},
            {"baggage", "bags"},
            {"bags"},
        };
        auto ret = suggestedProducts(products, "bags");
        assert(ret == expected);
    }
    {
        std::vector<std::string> products{"havana"};
        std::vector<std::vector<std::string>> expected{
            {}, {}, {}, {}, {}, {}, {},
        };
        auto ret = suggestedProducts(products, "tatiana");
        assert(ret == expected);
    }
    return 0;
}
