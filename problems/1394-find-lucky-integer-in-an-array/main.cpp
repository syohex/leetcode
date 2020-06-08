#include <cassert>
#include <vector>
#include <map>

int findLucky(const std::vector<int> &arr) {
    std::map<int, int> m;
    for (const auto i : arr) {
        ++m[i];
    }

    int max = -1;
    for (const auto &it : m) {
        if (it.first == it.second) {
            if (max < it.first) {
                max = it.first;
            }
        }
    }

    return max;
}

int main() {
    {
        std::vector<int> input{2, 2, 3, 4};
        assert(findLucky(input) == 2);
    }
    {
        std::vector<int> input{1, 2, 2, 3, 3, 3};
        assert(findLucky(input) == 3);
    }
    {
        std::vector<int> input{2, 2, 2, 3, 3};
        assert(findLucky(input) == -1);
    }
    {
        std::vector<int> input{5};
        assert(findLucky(input) == -1);
    }
    {
        std::vector<int> input{7, 7, 7, 7, 7, 7, 7};
        assert(findLucky(input) == 7);
    }
    return 0;
}
