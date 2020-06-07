#include <cassert>
#include <vector>
#include <map>

bool canBeEqual(const std::vector<int> &target, const std::vector<int> &arr) {
    if (target.size() != arr.size()) {
        return false;
    }

    std::map<int, int> target_map;
    for (const auto n : target) {
        ++target_map[n];
    }

    std::map<int, int> arr_map;
    for (const auto n : arr) {
        ++arr_map[n];
    }

    if (target_map.size() != arr_map.size()) {
        return false;
    }

    for (const auto &it : target_map) {
        const auto arr_it = arr_map.find(it.first);
        if (arr_it == arr_map.end()) {
            return false;
        }
        if (it.second != arr_it->second) {
            return false;
        }
    }

    return true;
}

int main() {
    assert((canBeEqual(std::vector<int>{1, 2, 3, 4}, std::vector<int>{2, 4, 1, 3})));
    assert((canBeEqual(std::vector<int>{7}, std::vector<int>{7})));
    assert((canBeEqual(std::vector<int>{1, 12}, std::vector<int>{12, 1})));
    assert(!(canBeEqual(std::vector<int>{3, 7, 9}, std::vector<int>{3, 7, 11})));
    assert((canBeEqual(std::vector<int>{1, 1, 1, 1, 1}, std::vector<int>{1, 1, 1, 1, 1})));
    return 0;
}
