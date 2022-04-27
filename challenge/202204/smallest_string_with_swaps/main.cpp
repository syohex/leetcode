#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <functional>

std::string smallestStringWithSwaps(const std::string &s, const std::vector<std::vector<int>> &pairs) {
    std::function<void(int node, const std::map<int, std::set<int>> &graph, std::vector<bool> &checked, std::vector<char> &chars,
                       std::vector<int> &indexes)>
        f;
    f = [&](int node, const std::map<int, std::set<int>> &graph, std::vector<bool> &checked, std::vector<char> &chars,
            std::vector<int> &indexes) {
        chars.push_back(s[node]);
        indexes.push_back(node);
        checked[node] = true;

        if (graph.find(node) == graph.end()) {
            return;
        }

        for (int next : graph.at(node)) {
            if (!checked[next]) {
                f(next, graph, checked, chars, indexes);
            }
        }
    };

    int len = s.size();
    std::map<int, std::set<int>> graph;

    for (const auto &pair : pairs) {
        graph[pair[0]].insert(pair[1]);
        graph[pair[1]].insert(pair[0]);
    }

    std::string ret(len, 0);
    std::vector<bool> checked(len, false);
    for (int i = 0; i < len; ++i) {
        if (!checked[i]) {
            std::vector<char> chars;
            std::vector<int> indexes;

            f(i, graph, checked, chars, indexes);

            std::sort(chars.begin(), chars.end());
            std::sort(indexes.begin(), indexes.end());

            for (size_t i = 0; i < chars.size(); ++i) {
                ret[indexes[i]] = chars[i];
            }
        }
    }

    return ret;
}

int main() {
    {
        std::string s("dcab");
        std::vector<std::vector<int>> pairs{{0, 3}, {1, 2}};
        auto ret = smallestStringWithSwaps(s, pairs);
        assert(ret == "bacd");
    }
    {
        std::string s("dcab");
        std::vector<std::vector<int>> pairs{{0, 3}, {1, 2}, {0, 2}};
        auto ret = smallestStringWithSwaps(s, pairs);
        assert(ret == "abcd");
    }
    {
        std::string s("cba");
        std::vector<std::vector<int>> pairs{{0, 1}, {1, 2}};
        auto ret = smallestStringWithSwaps(s, pairs);
        assert(ret == "abc");
    }
    {
        std::string s("dcab");
        std::vector<std::vector<int>> pairs;
        auto ret = smallestStringWithSwaps(s, pairs);
        assert(ret == "dcab");
    }
    return 0;
}
