#include <cassert>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

int minimumDeviation(const std::vector<int> &nums) {
    std::priority_queue<int> q;
    int min = INT_MAX;
    for (int num : nums) {
        if (num % 2 == 0) {
            q.push(num);
            min = std::min(min, num);
        } else {
            q.push(num * 2);
            min = std::min(min, num * 2);
        }
    }

    int ret = INT_MAX;
    while (!q.empty()) {
        int val = q.top();
        q.pop();

        ret = std::min(ret, val - min);
        if (val % 2 == 1) {
            break;
        }

        q.push(val / 2);
        min = std::min(min, val / 2);
    }

    return ret;
}

int main() {
    assert((minimumDeviation(std::vector<int>{1, 2, 3, 4})));
    assert((minimumDeviation(std::vector<int>{4, 1, 5, 20, 3})));
    assert((minimumDeviation(std::vector<int>{2, 10, 8})));
    assert((minimumDeviation(std::vector<int>{3, 5})));
    assert((minimumDeviation(std::vector<int>{10, 4, 3})));
    return 0;
}
