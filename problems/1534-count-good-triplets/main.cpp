#include <cassert>
#include <vector>
#include <functional>

int countGoodTriplets(const std::vector<int> &arr, int a, int b, int c) {
    int ret = 0;
    std::function<void(size_t n, const std::vector<int> &tmp)> f;
    f = [&f, a, b, c, &arr, &ret](size_t n, const std::vector<int> &tmp) {
        if (tmp.size() == 3) {
            int t = tmp[0] - tmp[1] > 0 ? tmp[0] - tmp[1] : tmp[1] - tmp[0];
            if (t > a) {
                return;
            }
            t = tmp[1] - tmp[2] > 0 ? tmp[1] - tmp[2] : tmp[2] - tmp[1];
            if (t > b) {
                return;
            }
            t = tmp[0] - tmp[2] > 0 ? tmp[0] - tmp[2] : tmp[2] - tmp[0];
            if (t > c) {
                return;
            }

            ++ret;
            return;
        }

        if (n >= arr.size()) {
            return;
        }

        std::vector<int> k = tmp;
        k.push_back(arr[n]);
        f(n + 1, k);
        f(n + 1, tmp);
    };

    f(0, std::vector<int>{});
    return ret;
}

int main() {
    {
        std::vector<int> arr{3, 0, 1, 1, 9, 7};
        assert(countGoodTriplets(arr, 7, 2, 3) == 4);
    }
    {
        std::vector<int> arr{1, 1, 2, 2, 3};
        assert(countGoodTriplets(arr, 0, 0, 1) == 0);
    }
    return 0;
}
