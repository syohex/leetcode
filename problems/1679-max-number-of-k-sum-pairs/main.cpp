#include <cassert>
#include <vector>
#include <map>

int maxOperations(const std::vector<int> &nums, int k) {
    std::map<int, int> m;
    for (const auto n : nums) {
        ++m[n];
    }

    int ret = 0;
    for (auto &it : m) {
        int pair = k - it.first;
        int count = it.second;
        for (int i = 0; i < count; ++i) {
            if (m.find(pair) != m.end() && m[pair] > 0) {
                if (pair == it.first && m[pair] < 2) {
                    continue;
                }

                ++ret;
                --m[it.first];
                --m[pair];
                if (pair == it.first) {
                    ++i;
                }
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 2, 3, 4};
        assert(maxOperations(nums, 5) == 2);
    }
    {
        std::vector<int> nums{3, 1, 3, 4, 3};
        assert(maxOperations(nums, 6) == 1);
    }
    return 0;
}
