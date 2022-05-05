#include <cassert>
#include <queue>

class MyStack {
  public:
    MyStack() {
    }

    void push(int x) {
        q1_.push(x);
        top_ = x;
    }

    int pop() {
        while (q1_.size() > 1) {
            top_ = q1_.front();
            q1_.pop();
            q2_.push(top_);
        }

        int ret = q1_.front();

        q1_ = q2_;
        q2_ = {};

        return ret;
    }

    int top() {
        return top_;
    }

    bool empty() {
        return q1_.empty();
    }

    std::queue<int> q1_;
    std::queue<int> q2_;
    int top_;
};

int main() {
    {
        MyStack s;
        s.push(1);
        s.push(2);
        assert(s.top() == 2);
        assert(s.pop() == 2);
        assert(s.top() == 1);
        assert(!s.empty());
    }
    return 0;
}
