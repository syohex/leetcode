#include <cassert>
#include <vector>
#include <cstdio>

int findSpecialInteger(const std::vector<int> &arr) {
    if (arr.size() == 1) {
        return arr[0];
    }

    size_t limit = arr.size() / 4 + 1;
    int prev = arr[0];
    size_t con = 1;
    for (size_t i = 1; i < arr.size();) {
        if (prev == arr[i]) {
            do {
                ++con;
                if (con >= limit) {
                    return arr[i];
                }
                ++i;
            } while (i < arr.size() && prev == arr[i]);
        }

        prev = arr[i];
        ++i;
        con = 1;
    }

    return -1;
}

int main() {
    {
        std::vector<int> input{1, 2, 2, 6, 6, 6, 6, 7, 10};
        assert(findSpecialInteger(input) == 6);
    }
    {
        std::vector<int> input{1, 2, 3, 4, 5, 5};
        assert(findSpecialInteger(input) == 5);
    }
    {
        std::vector<int> input{1, 1, 2, 3, 4};
        assert(findSpecialInteger(input) == 1);
    }
    {
        std::vector<int> input{1, 1, 2, 2, 3, 3, 3, 3};
        assert(findSpecialInteger(input) == 3);
    }
    return 0;
}
