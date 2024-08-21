#include <cassert>
#include <string>
#include <algorithm>
#include <functional>
#include <map>

int strangePrinter(std::string s) {
    const auto remove_dups = [](const std::string &s) -> std::string {
        int i = 0;
        int len = s.size();
        std::string ret;

        while (i < len) {
            ret.push_back(s[i]);

            char c = s[i++];
            while (i < len && s[i] == c) {
                ++i;
            }
        }

        return ret;
    };

    std::map<std::pair<int, int>, int> cache;

    std::function<int(int start, int end, const std::string &s)> f;
    f = [&](int start, int end, const std::string &s) -> int {
        if (start > end) {
            return 0;
        }

        std::pair<int, int> key{start, end};
        if (cache.find(key) != cache.end()) {
            return cache[key];
        }

        int ret = 1 + f(start + 1, end, s);
        for (int i = start + 1; i <= end; ++i) {
            if (s[start] == s[i]) {
                int ret_split = f(start, i - 1, s) + f(i + 1, end, s);
                ret = std::min(ret, ret_split);
            }
        }

        cache[key] = ret;
        return ret;
    };

    s = remove_dups(s);
    return f(0, s.size() - 1, s);
}

int main() {
    assert(strangePrinter("aaabbb") == 2);
    assert(strangePrinter("aba") == 2);
    return 0;
}
