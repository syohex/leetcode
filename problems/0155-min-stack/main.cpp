#include <cassert>
#include <vector>
#include <climits>
#include <cstdio>

class MinStack {
  public:
    MinStack() : elems_(0), min_(INT_MAX) {
    }

    void push(int x) {
        if (x < min_) {
            min_ = x;
        }

        if (elems_ < stack_.size()) {
            stack_[elems_] = x;
        } else {
            stack_.push_back(x);
        }
        ++elems_;
    }

    void pop() {
        if (min_ == stack_[elems_ - 1]) {
            int m = INT_MAX;
            for (size_t i = 0; i < elems_ - 1; ++i) {
                if (stack_[i] < m) {
                    m = stack_[i];
                }
            }

            min_ = m;
        }
        --elems_;
    }

    int top() {
        return stack_[elems_ - 1];
    }

    int getMin() {
        return min_;
    }

    std::vector<int> stack_;
    size_t elems_;
    int min_;

    void print() {
        printf("elems = %zd [", elems_);
        for (size_t i = 0; i < elems_; ++i) {
            printf(" %d ", stack_[i]);
        }
        printf("]\n");
    }
};

int main() {
    MinStack s;
    s.push(-2);
    s.push(0);
    s.push(-3);
    assert(s.getMin() == -3);
    s.pop();
    assert(s.top() == 0);
    assert(s.getMin() == -2);
}
