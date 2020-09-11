#include <cassert>
#include <vector>
#include <cstdio>
#include <map>

int findShortestSubArray(const std::vector<int> &nums) {
    struct Info {
        int count;
        int start;
        int end;
    };

    int max = 1;
    std::map<int, Info> m;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        if (m.find(nums[i]) == m.end()) {
            m[nums[i]] = Info{1, i, i};
        } else {
            ++m[nums[i]].count;
            if (m[nums[i]].count > max) {
                max = m[nums[i]].count;
            }
            m[nums[i]].end = i;
        }
    }

    if (max == 1) {
        return 1;
    }

    int ret = static_cast<int>(nums.size());
    for (const auto &it : m) {
        const auto &info = it.second;
        if (info.count == max) {
            int length = info.end - info.start + 1;
            if (ret > length) {
                ret = length;
            }
        }
    }

    return ret;
}

int main() {
    {
        std::vector<int> nums{1, 2, 2, 3, 1};
        assert(findShortestSubArray(nums) == 2);
    }
    {
        std::vector<int> nums{1, 2, 2, 3, 1, 4, 2};
        assert(findShortestSubArray(nums) == 6);
    }
    {
        std::vector<int> nums{1};
        assert(findShortestSubArray(nums) == 1);
    }
    {
        std::vector<int> nums{2, 1};
        assert(findShortestSubArray(nums) == 1);
    }
    return 0;
}
