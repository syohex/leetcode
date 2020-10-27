#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>

double trimMean(std::vector<int> &arr) {
    size_t remove = static_cast<size_t>(arr.size() * 0.05);
    std::sort(arr.begin(), arr.end());

    double sum = 0;
    for (size_t i = remove; i < arr.size() - remove; ++i) {
        sum += arr[i];
    }

    return sum / (arr.size() - (2 * remove));
}

void check(double a, double b) {
    double c = fabs(a - b);
    if (c > 0.0001) {
        printf("@@ got=%g, expected=%g\n", a, b);
        abort();
    }
}

int main() {
    {
        std::vector<int> a{1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3};
        auto ret = trimMean(a);
        check(ret, 2.00000);
    }
    {
        std::vector<int> a{6, 2, 7, 5, 1, 2, 0, 3, 10, 2, 5, 0, 5, 5, 0, 8, 7, 6, 8, 0};
        auto ret = trimMean(a);
        check(ret, 4.00000);
    }
    {
        std::vector<int> a{6, 0, 7, 0, 7, 5, 7, 8, 3,  4, 0, 7, 8, 1, 6, 8,  1, 1, 2, 4,
                           8, 1, 9, 5, 4, 3, 8, 5, 10, 8, 6, 6, 1, 0, 6, 10, 8, 2, 3, 4};
        auto ret = trimMean(a);
        check(ret, 4.77778);
    }
    {
        std::vector<int> a{9, 7, 8,  7, 7,  8, 4, 4,  6, 8, 8, 7, 6, 8, 8, 9, 2, 6, 0, 0, 1, 10, 8, 6, 3, 3, 5, 1, 10, 9,
                           0, 7, 10, 0, 10, 4, 1, 10, 6, 9, 3, 6, 0, 0, 2, 7, 0, 6, 7, 2, 9, 7,  7, 3, 0, 1, 6, 1, 10, 3};
        auto ret = trimMean(a);
        check(ret, 5.277778);
    }
    {
        std::vector<int> a{4,  8, 4,  10, 0, 7, 1, 3, 7, 8,  8,  3, 4, 1,  6, 2, 1, 1, 8,  0, 9, 8, 0, 3, 9,  10, 3,
                           10, 1, 10, 7,  3, 2, 1, 4, 9, 10, 7,  6, 4, 0,  8, 5, 1, 2, 1,  6, 2, 5, 0, 7, 10, 9,  10,
                           3,  7, 10, 5,  8, 5, 7, 6, 7, 6,  10, 9, 5, 10, 5, 5, 7, 2, 10, 7, 7, 8, 2, 0, 1,  1};
        auto ret = trimMean(a);
        check(ret, 5.29167);
    }
    return 0;
}
