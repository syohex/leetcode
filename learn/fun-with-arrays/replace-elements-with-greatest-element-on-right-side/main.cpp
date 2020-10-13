#include <cassert>
#include <vector>
#include <cstdio>

std::vector<int> replaceElements(std::vector<int> &arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        int max = 0;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (max < arr[j]) {
                max = arr[j];
            }
        }
        arr[i] = max;
    }

    arr.back() = -1;
    return arr;
}

int main() {
    {
        std::vector<int> input{17, 18, 5, 4, 6, 1};
        auto ret = replaceElements(input);
        assert(ret == input);
        assert((ret == std::vector<int>{18, 6, 6, 6, 1, -1}));
    }
    return 0;
}
