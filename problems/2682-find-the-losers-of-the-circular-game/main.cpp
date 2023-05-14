#include <cassert>
#include <vector>
#include <algorithm>
#include <set>

std::vector<int> circularGameLosers(int n, int k) {
    std::set<int> s;
    for (int i = 2; i <= n; ++i) {
        s.insert(i);
    }

    int ball = 0;
    int steps = 1;

    while (true) {
        ball = (ball + k * steps) % n;
        ++steps;

        auto it = s.find(ball + 1);
        if (it != s.end()) {
            s.erase(it);
        } else {
            break;
        }
    }

    return std::vector<int>(s.begin(), s.end());
}

int main() {
    {
        std::vector<int> expected{4, 5};
        auto ret = circularGameLosers(5, 2);
        assert(ret == expected);
    }
    {
        std::vector<int> expected{2, 3, 4};
        auto ret = circularGameLosers(4, 4);
        assert(ret == expected);
    }
    return 0;
}
