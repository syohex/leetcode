#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <climits>

std::vector<std::string> findRestaurant(const std::vector<std::string> &list1, const std::vector<std::string> &list2) {
    std::map<std::string, int> m;
    int i = 0;
    for (const auto &name : list1) {
        m[name] = i++;
    }

    std::vector<std::string> ret;
    int min = INT_MAX;
    i = 0;
    for (const auto &name : list2) {
        if (m.find(name) == m.end()) {
            ++i;
            continue;
        }

        int val = m[name] + i;
        if (min > val) {
            min = val;
            ret.clear();
            ret.push_back(name);
        } else if (min == val) {
            ret.push_back(name);
        }

        ++i;
    }

    return ret;
}

int main() {
    {
        std::vector<std::string> input1{"Shogun", "Tapioca Express", "Burger King", "KFC"};
        std::vector<std::string> input2{"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
        auto ret = findRestaurant(input1, input2);
        assert(ret.size() == 1);
        assert(ret[0] == "Shogun");
    }
    {
        std::vector<std::string> input1{"Shogun", "Tapioca Express", "Burger King", "KFC"};
        std::vector<std::string> input2{"KFC", "Shogun", "Burger King"};
        auto ret = findRestaurant(input1, input2);
        assert(ret.size() == 1);
        assert(ret[0] == "Shogun");
    }
    return 0;
}
