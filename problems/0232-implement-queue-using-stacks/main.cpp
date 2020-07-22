#include <cassert>
#include <list>

class MyQueue {
  public:
    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        list_.push_back(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = list_.front();
        list_.pop_front();
        return val;
    }

    /** Get the front element. */
    int peek() {
        return list_.front();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return list_.empty();
    }

  private:
    std::list<int> list_;
};

int main() {
    {
        MyQueue q;
        q.push(1);
        q.push(2);
        assert(q.peek() == 1);
        assert(q.pop() == 1);
        assert(q.peek() == 2);
        assert(!q.empty());
        assert(q.pop() == 2);
        assert(q.empty());
    }
    return 0;
}
