#include <cassert>
#include <vector>
#include <stack>

bool canReach(const std::vector<int> &arr, int start) {
    std::vector<bool> checked(arr.size(), false);
    std::stack<int> stack;
    stack.push(start);

    int len = arr.size();
    while (!stack.empty()) {
        int pos = stack.top();
        stack.pop();

        if (arr[pos] == 0) {
            return true;
        }

        int plus = pos + arr[pos];
        if (plus < len && !checked[plus]) {
            stack.push(plus);
            checked[plus] = true;
        }

        int minus = pos - arr[pos];
        if (minus >= 0 && !checked[minus]) {
            stack.push(minus);
            checked[minus] = true;
        }
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