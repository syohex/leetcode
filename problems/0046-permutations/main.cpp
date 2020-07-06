#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>

std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    std::vector<std::vector<int>> ret;
    std::function<void(std::vector<int> & nums, size_t left, size_t right)> f;
    f = [&ret, &f](std::vector<int> &nums, size_t left, size_t right) {
        if (left == right) {
            ret.push_back(nums);
            return;
        }

        for (size_t i = left; i <= right; ++i) {
            std::swap(nums[left], nums[i]);
            f(nums, left + 1, right);
            std::swap(nums[i], nums[left]);
        }
    };

    f(nums, 0, nums.size() - 1);
    return ret;
}

int main() {
    {
        std::vector<int> input{1, 2, 3};
        auto ret = permute(input);
        assert(ret.size() == 6);
        assert((std::find(ret.begin(), ret.end(), std::vector<int>{1, 2, 3}) != ret.end()));
        assert((std::find(ret.begin(), ret.end(), std::vector<int>{1, 3, 2}) != ret.end()));
        assert((std::find(ret.begin(), ret.end(), std::vector<int>{2, 1, 3}) != ret.end()));
        assert((std::find(ret.begin(), ret.end(), std::vector<int>{2, 3, 1}) != ret.end()));
        assert((std::find(ret.begin(), ret.end(), std::vector<int>{3, 1, 2}) != ret.end()));
        assert((std::find(ret.begin(), ret.end(), std::vector<int>{3, 2, 1}) != ret.end()));
    }
    return 0;
}
