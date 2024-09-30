#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdio>

class CustomStack {
  public:
    CustomStack(int maxSize) : stack_(maxSize, 0), top_(-1) {
    }

    void push(int x) {
        if (top_ + 1 < static_cast<int>(stack_.size())) {
            stack_[++top_] = x;
        }
    }

    int pop() {
        if (top_ < 0) {
            return -1;
        }

        return stack_[top_--];
    }

    void increment(int k, int val) {
        int len = std::min(k, top_ + 1);
        for (int i = 0; i < len; ++i) {
            stack_[i] += val;
        }
    }

    std::vector<int> stack_;
    int top_;
};

int main() {
    {
        CustomStack s(3);
        s.push(1);
        s.push(2);
        assert(s.pop() == 2);
        s.push(2);
        s.push(3);
        s.push(4);
        s.increment(5, 100);
        s.increment(2, 100);
        assert(s.pop() == 103);
        assert(s.pop() == 202);
        assert(s.pop() == 201);
        assert(s.pop() == -1);
    }
    return 0;
}