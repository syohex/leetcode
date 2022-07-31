#include <cassert>
#include <vector>
#include <algorithm>

int minimumOperations(const std::vector<int> &nums) {
    std::vector<int> v;
    for (int num : nums) {
        if (num > 0) {
            v.push_back(num);
        }
    }

    int ret = 0;
    while (!v.empty()) {
        std::sort(v.begin(), v.end());

        std::vector<int> tmp;
        for (size_t i = 1; i < v.size(); ++i) {
            int val = v[i] - v[0];
            if (val > 0) {
                tmp.push_back(val);
            }
        }

        v = std::move(tmp);
        ++ret;
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 5, 0, 3, 5};
        int ret = minimumOperations(nums);
        assert(ret == 3);
    }
    {
        std::vector<int> nums{0};
        int ret = minimumOperations(nums);
        assert(ret == 0);
    }
}
