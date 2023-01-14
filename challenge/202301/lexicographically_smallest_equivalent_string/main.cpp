#include <cassert>
#include <vector>
#include <string>
#include <functional>
#include <map>
#include <set>
#include <algorithm>

std::string smallestEquivalentString(const std::string &s1, const std::string &s2, const std::string &baseStr) {
    std::map<char, std::vector<char>> graph;

    for (size_t i = 0; i < s1.size(); ++i) {
        graph[s1[i]].push_back(s2[i]);
        graph[s2[i]].push_back(s1[i]);
    }

    std::function<char(char node, std::set<char> &visited)> f;
    f = [&](char node, std::set<char> &visited) -> char {
        visited.insert(node);

        char ret = node;
        for (char next : graph[node]) {
            if (visited.find(next) != visited.end()) {
                continue;
            }

            ret = std::min(ret, f(next, visited));
        }

        return ret;
    };

    std::vector<char> table(26, 0);
    for (int i = 0; i < 26; ++i) {
        if (table[i] != 0) {
            continue;
        }

        std::set<char> visited;
        char ret = f(i + 'a', visited);
        for (char d : visited) {
            table[d - 'a'] = ret;
        }
    }

    std::string ret;
    for (char c : baseStr) {
        ret.push_back(table[c - 'a']);
    }

    return ret;
}

int main() {
    {
        std::string s1("parker");
        std::string s2("morris");
        std::string baseStr("parser");

        auto ret = smallestEquivalentString(s1, s2, baseStr);
        assert(ret == "makkek");
    }
    {
        std::string s1("hello");
        std::string s2("world");
        std::string baseStr("hold");

        auto ret = smallestEquivalentString(s1, s2, baseStr);
        assert(ret == "hdld");
    }
    {
        std::string s1("leetcode");
        std::string s2("programs");
        std::string baseStr("sourcecode");

        auto ret = smallestEquivalentString(s1, s2, baseStr);
        assert(ret == "aauaaaaada");
    }
    return 0;
}
