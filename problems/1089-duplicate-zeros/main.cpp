#include <cassert>
#include <vector>

void duplicateZeros(std::vector<int> &arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == 0 && i != arr.size() - 1) {
            for (size_t j = arr.size() - 2; j >= i + 1; --j) {
                arr[j + 1] = arr[j];
            }

            arr[i + 1] = 0;
            ++i;
        }
    }
}

int main() {
    {
        std::vector<int> arr{1, 0, 2, 3, 0, 4, 5, 0};
        duplicateZeros(arr);
        assert((arr == std::vector<int>{1, 0, 0, 2, 3, 0, 0, 4}));
    }
    {
        std::vector<int> arr{1, 2, 3};
        duplicateZeros(arr);
        assert((arr == std::vector<int>{1, 2, 3}));
    }
    return 0;
}
