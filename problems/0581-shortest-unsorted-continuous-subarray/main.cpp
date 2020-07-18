#include <cassert>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>
#include <set>

int findUnsortedSubarray(const std::vector<int> &nums) {
    if (nums.size() == 1) {
        return 0;
    }

    auto tmp = nums;
    std::sort(tmp.begin(), tmp.end());

    std::map<int, std::set<size_t>> pos;
    for (size_t i = 0; i < nums.size(); ++i) {
        pos[tmp[i]].insert(i);
    }

    size_t start = 0;
    for (size_t i = 0; i < nums.size(); ++i, ++start) {
        auto &p = pos[nums[i]];
        if (p.find(i) == p.end()) {
            break;
        }
    }

    if (start == nums.size()) {
        return 0;
    }

    size_t end = nums.size() - 1;
    for (size_t i = end; i > start; --i, --end) {
        auto &p = pos[nums[i]];
        if (p.find(i) == p.end()) {
            break;
        }
    }

    return static_cast<int>(end - start + 1);
}

int main() {
    struct TestData {
        explicit TestData(std::vector<int> input, int expected) : input(std::move(input)), expected(expected) {
        }

        void print() const {
            printf("[");
            for (auto i : input) {
                printf(" %d ", i);
            }
            printf("] (expected=%d)\n", expected);
        }

        std::vector<int> input;
        int expected;
    };

    std::vector<TestData> data{
        TestData(std::vector<int>{2, 6, 4, 8, 10, 9, 15}, 5),
        TestData(std::vector<int>{1, 2, 3, 4}, 0),
        TestData(std::vector<int>{4, 3, 2, 1}, 4),
        TestData(std::vector<int>{1}, 0),
        TestData(std::vector<int>{1, 2, 3, 3, 3}, 0),
    };

    for (const auto &d : data) {
        d.print();
        assert(findUnsortedSubarray(d.input) == d.expected);
    }

    return 0;
}
