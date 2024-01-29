#include <cassert>
#include <stack>

class MyQueue {
  public:
    MyQueue() {
    }

    void push(int x) {
        s1_.push(x);
    }

    int pop() {
        while (s1_.size() > 1) {
            s2_.push(s1_.top());
            s1_.pop();
        }

        int ret = s1_.top();
        s1_.pop();

        while (!s2_.empty()) {
            s1_.push(s2_.top());
            s2_.pop();
        }

        return ret;
    }

    int peek() {
        while (s1_.size() > 1) {
            s2_.push(s1_.top());
            s1_.pop();
        }

        int ret = s1_.top();

        while (!s2_.empty()) {
            s1_.push(s2_.top());
            s2_.pop();
        }

        return ret;
    }

    bool empty() {
        return s1_.empty();
    }

    std::stack<int> s1_;
    std::stack<int> s2_;
};

int main() {
    {
        MyQueue q;
        q.push(1);
        q.push(2);
        assert(q.peek() == 1);
        q.pop();
        assert(q.peek() == 2);
        assert(!q.empty());
        q.pop();
        assert(q.empty());
    }
    return 0;
}
