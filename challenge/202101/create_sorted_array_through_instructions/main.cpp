#include <cassert>
#include <vector>
#include <map>
#include <algorithm>

int createSortedArray(const std::vector<int> &instructions) {
    std::map<int, int> m;
    long sum = 0;
    constexpr long mod = 1'000'000'000 + 7;

    for (int n : instructions) {
        long start = 0;
        for (const auto &it : m) {
            if (it.first >= n) {
                break;
            }

            start += it.second;
        }

        long end = 0;
        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            if (it->first <= n) {
                break;
            }

            end += it->second;
        }

        sum += std::min(start, end) % mod;
        ++m[n];
    }

    return static_cast<int>(sum);
}

int main() {
    {
        std::vector<int> input{1, 5, 6, 2};
        assert(createSortedArray(input) == 1);
    }
    {
        std::vector<int> input{1, 2, 3, 6, 5, 4};
        assert(createSortedArray(input) == 3);
    }
    {
        std::vector<int> input{1, 3, 3, 3, 2, 4, 2, 1, 2};
        assert(createSortedArray(input) == 4);
    }
    return 0;
}
