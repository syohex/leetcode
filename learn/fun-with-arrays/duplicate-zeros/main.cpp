#include <cassert>
#include <vector>
#include <cstdio>

void duplicateZeros(std::vector<int> &arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        if (arr[i] == 0) {
            for (size_t j = arr.size() - 1; j >= i + 1; --j) {
                arr[j] = arr[j - 1];
            }
            arr[i + 1] = 0;
            ++i;
        }
    }
}

int main() {
    {
        std::vector<int> input{1, 0, 2, 3, 0, 4, 5, 0};
        duplicateZeros(input);
        assert((input == std::vector<int>{1, 0, 0, 2, 3, 0, 0, 4}));
    }
    {
        std::vector<int> input{1, 2, 3};
        duplicateZeros(input);
        assert((input == std::vector<int>{1, 2, 3}));
    }
    return 0;
}
