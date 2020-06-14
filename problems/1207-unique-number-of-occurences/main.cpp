#include <cassert>
#include <vector>
#include <map>

bool uniqueOccurences(const std::vector<int> &arr) {
    std::map<int, int> m;
    for (auto i : arr) {
        ++m[i];
    }

    std::map<int, int> k;
    for (auto &it : m) {
        if (k[it.second] != 0) {
            return false;
        }

        ++k[it.second];
    }

    return true;
}

int main() {
    {
        std::vector<int> input{1, 2, 2, 1, 1, 3};
        assert(uniqueOccurences(input));
    }
    {
        std::vector<int> input{1, 2};
        assert(!uniqueOccurences(input));
    }
    {
        std::vector<int> input{-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
        assert(uniqueOccurences(input));
    }
    return 0;
}
