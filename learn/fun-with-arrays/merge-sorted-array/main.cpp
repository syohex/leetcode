#include <cassert>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdio>

void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    int i = 0, j = 0, k = 0;

    std::vector<int> v1;
    std::copy(nums1.begin(), nums1.begin() + m, std::back_inserter(v1));

    while (i < m && j < n) {
        if (v1[i] < nums2[j]) {
            nums1[k++] = v1[i++];
        } else if (v1[i] > nums2[j]) {
            nums1[k++] = nums2[j++];
        } else {
            nums1[k++] = v1[i++];
            nums1[k++] = nums2[j++];
        }
    }

    for (int ii = i; ii < m; ++ii) {
        nums1[k++] = v1[ii];
    }
    for (int jj = j; jj < n; ++jj) {
        nums1[k++] = nums2[jj];
    }
}

int main() {
    {
        std::vector<int> nums1{1, 2, 3, 0, 0, 0};
        std::vector<int> nums2{2, 5, 6};
        merge(nums1, 3, nums2, 3);
        assert((nums1 == std::vector<int>{1, 2, 2, 3, 5, 6}));
    }
    return 0;
}
