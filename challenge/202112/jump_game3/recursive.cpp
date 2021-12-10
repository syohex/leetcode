#include <cassert>
#include <vector>
#include <functional>

bool canReach(const std::vector<int> &arr, int start) {
    int len = arr.size();
    std::function<bool(int pos, std::vector<bool> &checked)> f;
    f = [&](int pos, std::vector<bool> &checked) -> bool {
        if (arr[pos] == 0) {
            return true;
        }

        int left = pos - arr[pos];
        if (left >= 0 && !checked[left]) {
            checked[left] = true;
            if (f(left, checked)) {
                return true;
            }
            checked[left] = false;
        }

        int right = pos + arr[pos];
        if (right < len && !checked[right]) {
            checked[right] = true;
            if (f(right, checked)) {
                return true;
            }
            checked[right] = false;
        }

        return false;
    };

    std::vector<bool> checked(len, false);
    return f(start, checked);
}

int main() {
    {
        std::vector<int> arr{4, 2, 3, 0, 3, 1, 2};
        assert(canReach(arr, 5));
    }
    {
        std::vector<int> arr{4, 2, 3, 0, 3, 1, 2};
        assert(canReach(arr, 0));
    }
    {
        std::vector<int> arr{3, 0, 2, 1, 2};
        assert(!canReach(arr, 2));
    }

    return 0;
}
