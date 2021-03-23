#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>

int threeSumMulti(std::vector<int> &arr, int target) {
    std::sort(arr.begin(), arr.end());

    long ret = 0;
    const long MOD = std::pow(10, 9) + 7;

    int limit = arr.size();
    for (int i = 0; i < limit - 2; ++i) {
        int left = i + 1;
        int right = limit - 1;
        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];
            if (sum == target) {
                if (arr[left] == arr[right]) {
                    long n = right - left;
                    ret = (ret + (n * (n + 1)) / 2) % MOD;
                    break;
                }
                long right_count = 1;
                int orig_left = left;
                int orig_right = right;
                int tmp = arr[right];
                --right;
                while (orig_left < right && tmp == arr[right]) {
                    --right;
                    ++right_count;
                }

                long left_count = 1;
                tmp = arr[left];
                ++left;
                while (left < orig_right && tmp == arr[left]) {
                    ++left;
                    ++left_count;
                }

                ret = (ret + left_count * right_count) % MOD;
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
    }

    return static_cast<int>(ret % MOD);
}

int main() {
    {
        std::vector<int> arr{1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
        assert(threeSumMulti(arr, 8) == 20);
    }
    {
        std::vector<int> arr{1, 1, 2, 2, 2, 2};
        assert(threeSumMulti(arr, 5) == 12);
    }

    return 0;
}
