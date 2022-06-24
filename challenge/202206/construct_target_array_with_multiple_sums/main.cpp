#include <cassert>
#include <vector>
#include <queue>
#include <cstdint>

bool isPossible(const std::vector<int> &target) {
    if (target.size() == 1) {
        return target[0] == 1;
    }

    std::priority_queue<std::int64_t> q;
    std::int64_t sum = 0;
    for (int n : target) {
        sum += n;
        q.push(n);
    }

    while (true) {
        std::int64_t val = q.top();
        if (val == 1) {
            break;
        }
        q.pop();

        std::int64_t rest = sum - val;
        if (rest == 1) {
            return true;
        }

        std::int64_t new_val = val % rest;
        if (new_val == 0 || new_val == val) {
            return false;
        }

        q.push(new_val);
        sum = sum - val + new_val;
    }

    return true;
}

int main() {
    {
        std::vector<int> target{9, 3, 5};
        assert(isPossible(target));
    }
    {
        std::vector<int> target{1, 1, 1, 2};
        assert(!isPossible(target));
    }
    {
        std::vector<int> target{8, 5};
        assert(isPossible(target));
    }
    return 0;
}
