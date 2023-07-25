#include <cassert>
#include <vector>

int peakIndexMontainArray(const std::vector<int> &arr) {
    int len = arr.size();
    int left = 0;
    int right = len - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < arr[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int main() {
    {
        std::vector<int> arr{0, 1, 0};
        int ret = peakIndexMontainArray(arr);
        assert(ret == 1);
    }
    {
        std::vector<int> arr{0, 2, 1, 0};
        int ret = peakIndexMontainArray(arr);
        assert(ret == 1);
    }
    {
        std::vector<int> arr{0, 10, 5, 2};
        int ret = peakIndexMontainArray(arr);
        assert(ret == 1);
    }
    return 0;
}
