#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>

std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
    std::sort(candidates.begin(), candidates.end());

    std::vector<std::vector<int>> ret;
    std::function<void(int sum, const std::vector<int> &nums, size_t index)> f;
    f = [&f, &candidates, &target, &ret](int sum, const std::vector<int> &nums, size_t index) {
        if (sum > target) {
            return;
        }
        if (index >= candidates.size()) {
            return;
        }
        if (candidates[index] > target) {
            return;
        }

        f(sum, nums, index + 1);

        auto tmp = nums;
        while (true) {
            sum += candidates[index];
            tmp.push_back(candidates[index]);
            if (sum < target) {
                f(sum, tmp, index + 1);
            } else if (sum == target) {
                ret.push_back(tmp);
                break;
            } else {
                break;
            }
        }
    };

    f(0, std::vector<int>{}, 0);
    return ret;
}

int main() {
    {
        std::vector<int> input{2, 3, 6, 7};
        auto ret = combinationSum(input, 7);
        assert(ret.size() == 2);
        assert((std::find(ret.begin(), ret.end(), std::vector<int>{2, 2, 3}) != ret.end()));
        assert((std::find(ret.begin(), ret.end(), std::vector<int>{7}) != ret.end()));
    }
    {
        std::vector<int> input{2, 3, 5};
        auto ret = combinationSum(input, 8);
        assert(ret.size() == 3);
        assert((std::find(ret.begin(), ret.end(), std::vector<int>{2, 2, 2, 2}) != ret.end()));
        assert((std::find(ret.begin(), ret.end(), std::vector<int>{2, 3, 3}) != ret.end()));
        assert((std::find(ret.begin(), ret.end(), std::vector<int>{3, 5}) != ret.end()));
    }
    {
        std::vector<int> input{2};
        auto ret = combinationSum(input, 8);
        assert(ret.size() == 1);
        assert((std::find(ret.begin(), ret.end(), std::vector<int>{2, 2, 2, 2}) != ret.end()));
    }
    return 0;
}
