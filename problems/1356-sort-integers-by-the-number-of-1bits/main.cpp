#include <cassert>
#include <vector>
#include <map>
#include <algorithm>

std::vector<int> sortByBits(const std::vector<int> &arr) {
    if (arr.size() <= 1) {
        return arr;
    }

    auto f = [](int n) {
        int count = 0;
        while (n > 0) {
            count += (n % 2);
            n /= 2;
        }

        return count;
    };

    std::map<int, int> m;
    for (const auto i : arr) {
        if (m.find(i) != m.end()) {
            continue;
        }

        m[i] = f(i);
    }

    std::vector<int> ret(arr);
    std::sort(ret.begin(), ret.end(), [&m](int a, int b) {
        if (m[a] != m[b]) {
            return m[a] < m[b];
        }

        return a < b;
    });
    return ret;
}

int main() {
    {
        std::vector<int> input{0, 1, 2, 3, 4, 5, 6, 7, 8};
        auto ret = sortByBits(input);
        assert((ret == std::vector<int>{0, 1, 2, 4, 8, 3, 5, 6, 7}));
    }
    {
        std::vector<int> input{1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
        auto ret = sortByBits(input);
        assert((ret == std::vector<int>{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024}));
    }
    {
        std::vector<int> input{10000, 10000};
        auto ret = sortByBits(input);
        assert((ret == std::vector<int>{10000, 10000}));
    }
    {
        std::vector<int> input{2, 3, 5, 7, 11, 13, 17, 19};
        auto ret = sortByBits(input);
        assert((ret == std::vector<int>{2, 3, 5, 17, 7, 11, 13, 19}));
    }
    {
        std::vector<int> input{10, 100, 1000, 10000};
        auto ret = sortByBits(input);
        assert((ret == std::vector<int>{10, 100, 10000, 1000}));
    }
    {
        std::vector<int> input{1111, 7644, 1107, 6978, 8742, 1, 7403, 7694, 9193, 4401, 377, 8641, 5311, 624, 3554, 6631};
        auto ret = sortByBits(input);
        assert(
            (ret == std::vector<int>{1, 624, 1107, 4401, 8641, 8742, 377, 1111, 6978, 3554, 7694, 9193, 5311, 6631, 7403, 7644}));
    }
    return 0;
}
