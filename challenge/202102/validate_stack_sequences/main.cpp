#include <cassert>
#include <vector>
#include <stack>

bool validateStackSequences(const std::vector<int> &pushed, const std::vector<int> &popped) {
    size_t p1 = 0, p2 = 0;
    std::stack<int> s;
    if (!pushed.empty()) {
        while (p1 < pushed.size() || p2 < popped.size()) {
            while (p1 < pushed.size() && (s.empty() || s.top() != popped[p2])) {
                s.push(pushed[p1++]);
            }

            if (s.top() != popped[p2]) {
                return false;
            }

            s.pop();
            ++p2;
        }
    }

    return s.empty() && p1 == pushed.size() && p2 == popped.size();
}

int main() {
    {
        std::vector<int> pushed{1, 2, 3, 4, 5};
        std::vector<int> popped{4, 5, 3, 2, 1};
        assert(validateStackSequences(pushed, popped));
    }
    {
        std::vector<int> pushed{1, 2, 3, 4, 5};
        std::vector<int> popped{4, 3, 5, 1, 2};
        assert(!validateStackSequences(pushed, popped));
    }
    return 0;
}
