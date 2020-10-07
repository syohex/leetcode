#include <cassert>
#include <vector>
#include <set>

bool checkIfExists(const std::vector<int> &arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t j = 0; j < arr.size(); ++j) {
            if (i == j) {
                continue;
            }

            if (arr[i] == 2 * arr[j]) {
                return true;
            }
        }
    }

    return false;
}

bool checkIfExists2(const std::vector<int> &arr) {
    std::set<int> s;
    for (const auto i : arr) {
        s.insert(i * 2);
    }

    for (const auto i : arr) {
        if (s.find(i) != s.end()) {
            return true;
        }
    }

    return false;
}

int main() {
    assert((checkIfExists(std::vector<int>{10, 2, 5, 3})));
    assert((checkIfExists(std::vector<int>{7, 1, 14, 11})));
    assert((!checkIfExists(std::vector<int>{3, 1, 7, 11})));

    assert((checkIfExists2(std::vector<int>{10, 2, 5, 3})));
    assert((checkIfExists2(std::vector<int>{7, 1, 14, 11})));
    assert((!checkIfExists2(std::vector<int>{3, 1, 7, 11})));
    return 0;
}
