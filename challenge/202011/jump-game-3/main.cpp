#include <cassert>
#include <vector>
#include <stack>

bool canReach(std::vector<int> &arr, int start) {
    int limit = static_cast<int>(arr.size());
    std::stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (arr[current] == 0) {
            return true;
        }
        if (arr[current] == -1) {
            continue;
        }

        int plus = current + arr[current];
        int minus = current - arr[current];
        if (plus < limit) {
            s.push(plus);
        }
        if (minus >= 0) {
            s.push(minus);
        }

        arr[current] = -1;
    }

    return false;
}

int main() {
    {
        std::vector<int> arr{4, 2, 3, 0, 3, 1, 2};
        assert(canReach(arr, 5));
    }
    {
        std::vector<int> arr{4, 2, 3, 0, 3, 1, 2};
        assert(canReach(arr, 0));
    }
    {
        std::vector<int> arr{3, 0, 2, 1, 2};
        assert(!canReach(arr, 2));
    }
    return 0;
}
