#include <cassert>
#include <vector>
#include <set>

int repeatedNTimes(const std::vector<int> &A) {
    std::set<int> s;
    for (const auto i : A) {
        if (s.find(i) != s.end()) {
            return i;
        }

        s.insert(i);
    }

    return 0;
}

int main() {
    {
        std::vector<int> input{1, 2, 3, 3};
        assert(repeatedNTimes(input) == 3);
    }
    {
        std::vector<int> input{2, 1, 2, 5, 3, 2};
        assert(repeatedNTimes(input) == 2);
    }
    {
        std::vector<int> input{5, 1, 5, 2, 5, 3, 5, 4};
        assert(repeatedNTimes(input) == 5);
    }
    return 0;
}
