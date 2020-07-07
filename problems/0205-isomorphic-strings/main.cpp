#include <cassert>
#include <string>
#include <vector>
#include <functional>
#include <map>

bool isIsomorphic(const std::string &s, const std::string &t) {
    if (s.empty() && t.empty()) {
        return true;
    }
    if (s.empty() || t.empty()) {
        return false;
    }

    auto f = [](const std::string &str) -> std::vector<size_t> {
        std::vector<size_t> v(str.size());
        std::map<char, size_t> cache;
        v[0] = 0;
        for (size_t i = 1; i < str.size(); ++i) {
            if (cache.find(str[i]) != cache.end()) {
                v[i] = cache[str[i]];
                continue;
            }

            bool found = false;
            for (size_t j = 0; j < i; ++j) {
                if (str[i] == str[j]) {
                    found = true;
                    v[i] = v[j];
                    cache[str[i]] = v[j];
                    break;
                }
            }

            if (!found) {
                v[i] = i;
            }
        }

        return v;
    };

    return f(s) == f(t);
}

int main() {
    assert(isIsomorphic("egg", "add"));
    assert(!isIsomorphic("foo", "bar"));
    assert(isIsomorphic("paper", "title"));
    assert(!isIsomorphic("aba", "baa"));
    return 0;
}
