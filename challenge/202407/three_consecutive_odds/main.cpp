#include <cassert>
#include <vector>

bool threeConsecutiveOdds(const std::vector<int> &arr) {
    int len = arr.size();

    for (int i = 0; i < len - 2; ++i) {
        bool ok = true;
        for (int j = 0; j < 3; ++j) {
            if (arr[i + j] % 2 == 0) {
                ok = false;
                break;
            }
        }

        if (ok) {
            return true;
        }
    }

    return false;
}

int main() {
    {
        std::vector<int> arr{2, 6, 4, 1};
        assert(!threeConsecutiveOdds(arr));
    }
    {
        std::vector<int> arr{1, 2, 34, 3, 4, 5, 7, 23, 12};
        assert(threeConsecutiveOdds(arr));
    }
    {
        std::vector<int> arr{1,1,1};
        assert(threeConsecutiveOdds(arr));
    }
    return 0;
}
