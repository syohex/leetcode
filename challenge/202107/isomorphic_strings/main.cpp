#include <cassert>
#include <string>
#include <map>
#include <vector>

bool isIsomorphic(std::string &s, std::string &t) {
    const auto f = [](const std::string &str) -> std::vector<int> {
        std::vector<int> v(str.size());
        std::map<char, int> m;
        int count = 1;
        for (size_t i = 0; i < str.size(); ++i) {
            if (m.find(str[i]) != m.end()) {
                v[i] = m[str[i]];
            } else {
                m[str[i]] = v[i] = count;
                ++count;
            }
        }
        return v;
    };

    return f(s) == f(t);
}

int main() {
    {
        std::string s("egg");
        std::string t("add");
        assert(isIsomorphic(s, t));
    }
    {
        std::string s("foo");
        std::string t("bar");
        assert(!isIsomorphic(s, t));
    }
    {
        std::string s("paper");
        std::string t("title");
        assert(isIsomorphic(s, t));
    }
    return 0;
}
