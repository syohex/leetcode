#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>

bool wordPattern(const std::string &pattern, const std::string &s) {
    std::vector<std::string> v;
    std::string tmp;

    std::stringstream ss(s);
    while (std::getline(ss, tmp, ' ')) {
        v.push_back(tmp);
    }

    if (pattern.size() != v.size()) {
        return false;
    }

    std::map<char, std::string> m;
    std::set<std::string> registered;

    for (size_t i = 0; i < v.size(); ++i) {
        if (m.find(pattern[i]) == m.end()) {
            if (registered.find(v[i]) != registered.end()) {
                return false;
            }

            m[pattern[i]] = v[i];
            registered.insert(v[i]);
        } else {
            if (m[pattern[i]] != v[i]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    {
        std::string pattern("abba");
        std::string s("dog cat cat dog");
        bool ret = wordPattern(pattern, s);
        assert(ret);
    }
    {
        std::string pattern("abba");
        std::string s("dog cat cat fish");
        bool ret = wordPattern(pattern, s);
        assert(!ret);
    }
    {
        std::string pattern("aaaa");
        std::string s("dog cat cat dog");
        bool ret = wordPattern(pattern, s);
        assert(!ret);
    }
    {
        std::string pattern("abba");
        std::string s("fish whoops helloworld fish");
        bool ret = wordPattern(pattern, s);
        assert(!ret);
    }
    {
        std::string pattern("aaa");
        std::string s("aa aa aa aa");
        bool ret = wordPattern(pattern, s);
        assert(!ret);
    }
    {
        std::string pattern("abba");
        std::string s("dog dog dog dog");
        bool ret = wordPattern(pattern, s);
        assert(!ret);
    }
    return 0;
}
