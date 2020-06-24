#include <cassert>
#include <vector>
#include <climits>
#include <cstdio>

std::vector<int> replaceElements(const std::vector<int> &arr) {
    std::vector<int> ret(arr.size());
    for (size_t i = 1; i < arr.size();) {
        int max = arr[i];
        size_t index = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (max < arr[j]) {
                max = arr[j];
                index = j;
            }
        }

        if (index > i) {
            for (size_t j = i - 1; j < index; ++j, ++i) {
                ret[j] = max;
            }
        } else {
            ret[i - 1] = max;
            ++i;
        }
    }
    ret[arr.size() - 1] = -1;
    return ret;
}

int main() {
    {
        std::vector<int> input{17, 18, 5, 4, 6, 1};
        auto ret = replaceElements(input);
        assert((ret == std::vector<int>{18, 6, 6, 6, 1, -1}));
    }
    return 0;
}
