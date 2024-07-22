#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> sortPeople(const std::vector<std::string> &names, const std::vector<int> &heights) {
    std::vector<std::pair<std::size_t, int>> d;
    for (std::size_t i = 0; i < heights.size(); ++i) {
        d.push_back({i, heights[i]});
    }

    std::sort(d.begin(), d.end(), [](const auto &a, const auto &b) { return a.second > b.second; });

    std::vector<std::string> ret;
    for (const auto &a : d) {
        ret.push_back(names[a.first]);
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> names{"Mary", "John", "Emma"};
        std::vector<int> heights{180, 165, 170};
        std::vector<std::string> expected{"Mary", "Emma", "John"};
        auto ret = sortPeople(names, heights);
        assert(ret == expected);
    }
    {
        std::vector<std::string> names{"Alice", "Bob", "Bob"};
        std::vector<int> heights{155, 185, 150};
        std::vector<std::string> expected{"Bob", "Alice", "Bob"};
        auto ret = sortPeople(names, heights);
        assert(ret == expected);
    }
    return 0;
}