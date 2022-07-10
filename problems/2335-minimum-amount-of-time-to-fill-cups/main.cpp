#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>

int fillCups(std::vector<int> &amount) {
    std::priority_queue<int> q;
    for (int a : amount) {
        q.push(a);
    }

    int ret = 0;
    while (true) {
        int a = q.top();
        if (a == 0) {
            break;
        }
        q.pop();
        int b = q.top();
        q.pop();

        if (a > 0) {
            --a;
        }
        if (b > 0) {
            --b;
        }

        ++ret;
        q.push(a);
        q.push(b);
    }

    return ret;
}

int main() {
    {
        std::vector<int> amount{1, 4, 2};
        int ret = fillCups(amount);
        assert(ret == 4);
    }
    {
        std::vector<int> amount{5, 4, 4};
        int ret = fillCups(amount);
        assert(ret == 7);
    }
    {
        std::vector<int> amount{5, 0, 0};
        int ret = fillCups(amount);
        assert(ret == 5);
    }
    return 0;
}
