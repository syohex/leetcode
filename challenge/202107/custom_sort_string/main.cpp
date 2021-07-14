#include <cassert>
#include <string>
#include <algorithm>
#include <map>

std::string customSortString(const std::string &order, std::string &str) {
    std::map<char, size_t> m;
    size_t i = 0;
    for (; i < order.size(); ++i) {
        m[order[i]] = i;
    }
    for (char c : str) {
        if (m.find(c) == m.end()) {
            m[c] = i++;
        }
    }

    const auto cmp = [&m](char a, char b) { return m[a] < m[b]; };

    std::sort(str.begin(), str.end(), cmp);
    return str;
}

int main() {
    {
        std::string order("cba");
        std::string str("abcd");
        auto ret = customSortString(order, str);
        assert(ret == "cbad");
    }
    return 0;
}
