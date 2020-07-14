#include <cassert>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

std::vector<int> relativeSortArray(std::vector<int> &arr1, std::vector<int> &arr2) {
    std::map<int, int> m1;
    for (int a : arr1) {
        ++m1[a];
    }

    std::set<int> s2;
    for (int a : arr2) {
        s2.insert(a);
    }

    std::vector<int> notContain;
    for (const auto &it : m1) {
        if (s2.find(it.first) == s2.end()) {
            for (int i = 0; i < it.second; ++i) {
                notContain.push_back(it.first);
            }
        }
    }

    std::vector<int> ret;
    for (int a : arr2) {
        for (int i = 0; i < m1[a]; ++i) {
            ret.push_back(a);
        }
    }

    std::copy(notContain.begin(), notContain.end(), std::back_inserter(ret));
    return ret;
}

int main() {
    {
        std::vector<int> arr1{2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
        std::vector<int> arr2{2, 1, 4, 3, 9, 6};
        auto ret = relativeSortArray(arr1, arr2);
        assert((ret == std::vector<int>{2, 2, 2, 1, 4, 3, 3, 9, 6, 7, 19}));
    }
    return 0;
}
