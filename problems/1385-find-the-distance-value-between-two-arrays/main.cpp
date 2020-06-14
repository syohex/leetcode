#include <cassert>
#include <vector>
#include <cstdio>

int findTheDistanceValue(const std::vector<int> &arr1, const std::vector<int> &arr2, int d) {
    int ret = 0;
    for (size_t i = 0; i < arr1.size(); ++i) {
        bool found = false;
        for (size_t j = 0; j < arr2.size(); ++j) {
            int diff = arr1[i] < arr2[j] ? arr2[j] - arr1[i] : arr1[i] - arr2[j];
            if (diff <= d) {
                found = true;
                break;
            }
        }

        if (!found) {
            ++ret;
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> arr1{4, 5, 8};
        std::vector<int> arr2{10, 9, 1, 8};
        assert(findTheDistanceValue(arr1, arr2, 2) == 2);
    }
    {
        std::vector<int> arr1{1, 4, 2, 3};
        std::vector<int> arr2{-4, -3, 6, 10, 20, 30};
        assert(findTheDistanceValue(arr1, arr2, 3) == 2);
    }
    {
        std::vector<int> arr1{2, 1, 100, 3};
        std::vector<int> arr2{-5, -2, 10, -3, 7};
        assert(findTheDistanceValue(arr1, arr2, 6) == 1);
    }
    return 0;
}
