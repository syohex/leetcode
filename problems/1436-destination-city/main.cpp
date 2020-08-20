#include <cassert>
#include <vector>
#include <string>
#include <map>

std::string destCity(const std::vector<std::vector<std::string>> &paths) {
    if (paths.size() == 1) {
        return paths[0][1];
    }

    std::map<std::string, std::string> m;
    for (const auto &path : paths) {
        m[path[0]] = path[1];
    }

    auto it = m.begin();
    while (true) {
        auto tmp = m.find(it->second);
        if (tmp == m.end()) {
            return it->second;
        }

        it = tmp;
    }

    return "";
}

int main() {
    {
        std::vector<std::vector<std::string>> input{
            {"London", "New York"},
            {"New York", "Lima"},
            {"Lima", "Sao Paulo"},
        };
        auto ret = destCity(input);
        assert(ret == "Sao Paulo");
    }
    {
        std::vector<std::vector<std::string>> input{
            {"B", "C"},
            {"D", "B"},
            {"C", "A"},
        };
        auto ret = destCity(input);
        assert(ret == "A");
    }
    {
        std::vector<std::vector<std::string>> input{
            {"A", "Z"},
        };
        auto ret = destCity(input);
        assert(ret == "Z");
    }
    return 0;
}
