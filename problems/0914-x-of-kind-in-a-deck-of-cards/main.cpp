#include <cassert>
#include <vector>
#include <map>
#include <climits>
#include <functional>

bool hasGroupsSizeX(const std::vector<int> &deck) {
    const auto f = [](int a, int b) -> int {
        if (a < b) {
            std::swap(a, b);
        }

        while (true) {
            int mod = a % b;
            if (mod == 0) {
                return b;
            }

            a = b;
            b = mod;
        }

        return 1;
    };

    std::map<int, int> m;
    for (auto i : deck) {
        ++m[i];
    }

    auto it = m.begin();
    int max_common_divisor = it->second;
    ++it;

    for (; it != m.end(); ++it) {
        max_common_divisor = f(it->second, max_common_divisor);
        if (max_common_divisor == 1) {
            return false;
        }
    }

    return max_common_divisor != 1;
}

int main() {
    {
        std::vector<int> input{1, 2, 3, 4, 4, 3, 2, 1};
        assert(hasGroupsSizeX(input));
    }
    {
        std::vector<int> input{1, 1, 1, 2, 2, 2, 3, 3};
        assert(!hasGroupsSizeX(input));
    }
    {
        std::vector<int> input{1};
        assert(!hasGroupsSizeX(input));
    }
    {
        std::vector<int> input{1, 1};
        assert(hasGroupsSizeX(input));
    }
    {
        std::vector<int> input{1, 1, 2, 2, 2, 2};
        assert(hasGroupsSizeX(input));
    }
    {
        std::vector<int> input{1, 1, 1, 1, 2, 2, 2, 2, 2, 2};
        assert(hasGroupsSizeX(input));
    }
    return 0;
}
