#include <cassert>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>

std::vector<std::vector<std::string>> findDuplicate(const std::vector<std::string> &paths) {
    const auto split = [](const std::string &s) -> std::vector<std::string> {
        std::stringstream ss(s);
        std::vector<std::string> v;
        std::string tmp;
        while (std::getline(ss, tmp, ' ')) {
            v.push_back(tmp);
        }

        return v;
    };

    const auto extract = [](const std::string &s, std::string &base, std::string &content) {
        auto pos = s.find('(');
        base = s.substr(0, pos);
        content = s.substr(pos + 1);
        content.pop_back();
    };

    std::map<std::string, std::vector<std::string>> m;
    for (const auto &path : paths) {
        auto parts = split(path);
        std::string base, content;
        for (size_t i = 1; i < parts.size(); ++i) {
            extract(parts[i], base, content);

            const auto full_path = parts[0] + "/" + base;
            m[content].push_back(full_path);
        }
    }

    std::vector<std::vector<std::string>> ret;
    for (const auto &it : m) {
        if (it.second.size() >= 2) {
            ret.push_back(it.second);
        }
    }

    return ret;
}

void check(const std::vector<std::vector<std::string>> &got, const std::vector<std::vector<std::string>> &expected) {
    std::set<std::set<std::string>> got_s;
    for (const auto &v : got) {
        std::set<std::string> tmp;
        for (const auto &s : v) {
            tmp.insert(s);
        }

        got_s.insert(tmp);
    }

    std::set<std::set<std::string>> expected_s;
    for (const auto &v : expected) {
        std::set<std::string> tmp;
        for (const auto &s : v) {
            tmp.insert(s);
        }

        expected_s.insert(tmp);
    }

    assert(got_s == expected_s);
}

int main() {
    {
        std::vector<std::string> paths{"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)",
                                       "root 4.txt(efgh)"};
        std::vector<std::vector<std::string>> expected{
            {"root/a/2.txt", "root/c/d/4.txt", "root/4.txt"},
            {"root/a/1.txt", "root/c/3.txt"},
        };
        auto ret = findDuplicate(paths);
        check(ret, expected);
    }
    {
        std::vector<std::string> paths{"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)"};
        std::vector<std::vector<std::string>> expected{
            {"root/a/2.txt", "root/c/d/4.txt"},
            {"root/a/1.txt", "root/c/3.txt"},
        };
        auto ret = findDuplicate(paths);
        check(ret, expected);
    }
    {
        std::vector<std::string> paths{"root/a 1.txt(abcd) 2.txt(efsfgh)", "root/c 3.txt(abdfcd)", "root/c/d 4.txt(efggdfh)"};
        auto ret = findDuplicate(paths);
        assert(ret.empty());
    }
    return 0;
}
