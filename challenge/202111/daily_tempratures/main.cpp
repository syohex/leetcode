#include <cassert>
#include <vector>
#include <stack>

std::vector<int> dailyTempratures(const std::vector<int> &temperatures) {
    std::vector<int> ret(temperatures.size());
    std::stack<size_t> stack;

    for (size_t i = 0; i < temperatures.size(); ++i) {
        while (!stack.empty() && temperatures[stack.top()] < temperatures[i]) {
            size_t index = stack.top();
            stack.pop();

            ret[index] = i - index;
        }

        stack.push(i);
    }

    while (!stack.empty()) {
        size_t index = stack.top();
        stack.pop();
        ret[index] = 0;
    }

    return ret;
}

int main() {
    {
        std::vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
        std::vector<int> expected{1, 1, 4, 2, 1, 1, 0, 0};
        auto ret = dailyTempratures(temperatures);
        assert(ret == expected);
    }
    {
        std::vector<int> temperatures{30, 40, 50, 60};
        std::vector<int> expected{1, 1, 1, 0};
        auto ret = dailyTempratures(temperatures);
        assert(ret == expected);
    }
    {
        std::vector<int> temperatures{30, 60, 90};
        std::vector<int> expected{1, 1, 0};
        auto ret = dailyTempratures(temperatures);
        assert(ret == expected);
    }
    return 0;
}