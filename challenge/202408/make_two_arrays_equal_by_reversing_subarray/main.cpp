#include <cassert>
#include <vector>
#include <algorithm>

bool canBeEqual(std::vector<int> &target, std::vector<int> &arr) {
    std::sort(target.begin(), target.end());
    std::sort(arr.begin(), arr.end());
    return target == arr;
}

int main() {
    {
        std::vector<int> target{1, 2, 3, 4};
        std::vector<int> arr{2, 4, 1, 3};
        assert(canBeEqual(target, arr));
    }
    {
        std::vector<int> target{7};
        std::vector<int> arr{7};
        assert(canBeEqual(target, arr));
    }
    {
        std::vector<int> target{3, 7, 9};
        std::vector<int> arr{3, 7, 11};
        assert(!canBeEqual(target, arr));
    }
    return 0;
}
