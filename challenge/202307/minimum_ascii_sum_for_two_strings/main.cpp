#include <cassert>
#include <string>
#include <algorithm>
#include <functional>
#include <map>

int minimumDeleteSum(const std::string &s1, const std::string &s2) {
    std::map<std::pair<int, int>, int> cache;

    std::function<int(int i, int j)> f = [&](int i, int j) -> int {
        if (i < 0 && j < 0) {
            return 0;
        }

        std::pair<int, int> key{i, j};
        if (cache.find(key) != cache.end()) {
            return cache[key];
        }

        if (i < 0) {
            cache[key] = s2[j] + f(i, j - 1);
            return cache[key];
        }
        if (j < 0) {
            cache[key] = s1[i] + f(i - 1, j);
            return cache[key];
        }

        if (s1[i] == s2[j]) {
            cache[key] = f(i - 1, j - 1);
            return cache[key];
        }

        int ret1 = s1[i] + f(i - 1, j);
        int ret2 = s2[j] + f(i, j - 1);
        cache[key] = std::min(ret1, ret2);
        return cache[key];
    };

    int ret = f(s1.size() - 1, s2.size() - 1);
    return ret;
}

int main() {
    {
        std::string s1("sea");
        std::string s2("eat");
        int ret = minimumDeleteSum(s1, s2);
        assert(ret == 231);
    }
    {
        std::string s1("delete");
        std::string s2("leet");
        int ret = minimumDeleteSum(s1, s2);
        assert(ret == 403);
    }
    return 0;
}
