#include <cassert>
#include <vector>
#include <cstddef>

bool validMountainArray(const std::vector<int> &arr) {
    if (arr.size() < 3) {
        return false;
    }

    bool is_up = true;
    bool has_up = false;
    for (size_t i = 1; i < arr.size(); ++i) {
        int diff = arr[i] - arr[i - 1];
        if (diff == 0) {
            return false;
        }

        if (is_up) {
            if (diff < 0) {
                is_up = false;
            } else {
                has_up = true;
            }
        } else {
            if (!has_up) {
                return false;
            }

            if (diff > 0) {
                return false;
            }
        }
    }

    return !is_up;
}

int main() {
    {
        std::vector<int> arr{2, 1};
        assert(!validMountainArray(arr));
    }
    {
        std::vector<int> arr{3, 5, 5};
        assert(!validMountainArray(arr));
    }
    {
        std::vector<int> arr{0, 3, 2, 1};
        assert(validMountainArray(arr));
    }
    {
        std::vector<int> arr{0, 1, 2, 3};
        assert(!validMountainArray(arr));
    }
    {
        std::vector<int> arr{4, 3, 2, 1};
        assert(!validMountainArray(arr));
    }
    return 0;
}
