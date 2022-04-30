#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include <set>

std::vector<double> calcEquation(const std::vector<std::vector<std::string>> &equations, const std::vector<double> &values,
                                 const std::vector<std::vector<std::string>> &queries) {

    std::function<double(const std::map<std::string, std::map<std::string, double>> &graph, const std::string &cur,
                         const std::string &dest, double acc, std::set<std::string> &checked)>
        f;
    f = [&f](const std::map<std::string, std::map<std::string, double>> &graph, const std::string &cur, const std::string &dest,
             double acc, std::set<std::string> &checked) -> double {
        checked.insert(cur);

        const auto &adjacents = graph.at(cur);
        if (adjacents.find(dest) != adjacents.end()) {
            return acc * adjacents.at(dest);
        }

        double ret = -1.0;
        for (const auto &it : adjacents) {
            const auto &node = it.first;
            if (checked.find(node) != checked.end()) {
                continue;
            }

            ret = f(graph, node, dest, acc * it.second, checked);
            if (ret != -1.0) {
                break;
            }
        }

        checked.erase(cur);
        return ret;
    };

    std::map<std::string, std::map<std::string, double>> graph;
    for (size_t i = 0; i < equations.size(); ++i) {
        const std::string &numerator = equations[i][0];
        const std::string &denominator = equations[i][1];
        double value = values[i];

        graph[numerator][denominator] = value;
        graph[denominator][numerator] = 1.0 / value;
    }

    std::vector<double> ret;
    for (size_t i = 0; i < queries.size(); ++i) {
        const std::string &numerator = queries[i][0];
        const std::string &denominator = queries[i][1];

        if (graph.find(numerator) == graph.end() || graph.find(denominator) == graph.end()) {
            ret.push_back(-1.0);
        } else if (numerator == denominator) {
            ret.push_back(1.0);
        } else {
            std::set<std::string> checked;
            ret.push_back(f(graph, numerator, denominator, 1.0, checked));
        }
    }

    return ret;
}

int main() {
    {
        std::vector<std::vector<std::string>> equations{{"a", "b"}, {"b", "c"}};
        std::vector<double> values{2.0, 3.0};
        std::vector<std::vector<std::string>> queries{{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
        std::vector<double> expected{6.0, 0.5, -1, 1, -1};

        auto ret = calcEquation(equations, values, queries);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<std::string>> equations{{"a", "b"}, {"b", "c"}, {"bc", "cd"}};
        std::vector<double> values{1.5, 2.5, 5.0};
        std::vector<std::vector<std::string>> queries{{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}};
        std::vector<double> expected{3.75, 0.4, 5.0, 0.2};

        auto ret = calcEquation(equations, values, queries);
        assert(ret == expected);
    }
    {
        std::vector<std::vector<std::string>> equations{{"a", "b"}};
        std::vector<double> values{0.5};
        std::vector<std::vector<std::string>> queries{{"a", "b"}, {"b", "a"}, {"a", "c"}, {"x", "y"}};
        std::vector<double> expected{0.5, 2.0, -1, -1};

        auto ret = calcEquation(equations, values, queries);
        assert(ret == expected);
    }
    return 0;
}