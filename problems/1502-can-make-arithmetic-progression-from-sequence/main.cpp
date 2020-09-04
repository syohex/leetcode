#include <cassert>
#include <vector>
#include <algorithm>

bool canMakeArithmeticProgression(std::vector<int> &arr) {
    std::sort(arr.begin(), arr.end());

    int diff = arr[1] - arr[0];
    for (size_t i = 1; i < arr.size() - 1; ++i) {
        if (arr[i + 1] - arr[i] != diff) {
            return false;
        }
    }

    return true;
}

int main() {
    {
        std::vector<int> input{3, 5, 1};
        assert(canMakeArithmeticProgression(input));
    }
    {
        std::vector<int> input{1, 2, 4};
        assert(!canMakeArithmeticProgression(input));
    }
    return 0;
}
