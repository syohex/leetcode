#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <map>

std::vector<std::string> uncommonFromSentences(const std::string& s1, const std::string& s2) {
    const auto f = [](const std::string& s) -> std::map<std::string, int> {
        std::map<std::string, int> ret;
        std::stringstream ss(s);
        std::string tmp;

        while (std::getline(ss, tmp, ' ')) {
            ++ret[tmp];
        }

        return ret;
    };

    const auto a = f(s1);
    const auto b = f(s2);

    std::vector<std::string> ret;
    for (const auto& [k, v] : a) {
        if (v > 1) {
            continue;
        }

        if (auto it = b.find(k); it == b.end()) {
            ret.push_back(k);
        }
    }

    for (const auto& [k, v] : b) {
        if (v > 1) {
            continue;
        }

        if (auto it = a.find(k); it == a.end()) {
            ret.push_back(k);
        }
    }


    return ret;
}

int main() {
    {
        std::string s1{"this apple is sweet"};
        std::string s2{"this apple is sour"};
        std::set<std::string> expected{"sweet", "sour"};

        auto ret = uncommonFromSentences(s1, s2);
        std::set<std::string> r(ret.begin(), ret.end());
        assert(r == expected);
    }
    {
        std::string s1{"apple apple"};
        std::string s2{"banana"};
        std::set<std::string> expected{"banana"};

        auto ret = uncommonFromSentences(s1, s2);
        std::set<std::string> r(ret.begin(), ret.end());
        assert(r == expected);
    }
    return 0;
}
