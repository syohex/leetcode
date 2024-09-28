#include <cassert>
#include <vector>
#include <cstdio>

class MyCircularDeque {
  public:
    MyCircularDeque(int k) : q_(k, 0), start_(0), end_(k - 1), size_(0), capacity_(k) {
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }

        start_ = (start_ - 1 + capacity_) % capacity_;
        q_[start_] = value;
        size_ += 1;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        end_ = (end_ + 1) % capacity_;
        q_[end_] = value;
        size_ += 1;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }

        start_ = (start_ + 1) % capacity_;
        size_ -= 1;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

        end_ = (end_ - 1 + capacity_) % capacity_;
        size_ -= 1;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }

        return q_[start_];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }

        return q_[end_];
    }

    bool isEmpty() {
        return size_ == 0;
    }

    bool isFull() {
        return size_ == capacity_;
    }

    std::vector<int> q_;
    int start_;
    int end_;
    int size_;
    int capacity_;
};

int main() {
    {
        MyCircularDeque q(3);
        assert(q.insertLast(1));
        assert(q.insertLast(2));
        assert(q.insertFront(3));
        assert(!q.insertFront(4));
        assert(q.getRear() == 2);
        assert(q.isFull());
        assert(q.deleteLast());
        assert(q.insertFront(4));
        assert(q.getFront() == 4);
    }
    {
        MyCircularDeque q(5);
        assert(q.insertFront(7));
        assert(q.insertLast(0));
        assert(q.getFront() == 7);
        assert(q.insertLast(3));
        assert(q.getFront() == 7);
        assert(q.insertFront(9));
        assert(q.getRear() == 3);
        assert(q.getFront() == 9);
        assert(q.getFront() == 9);
        assert(q.deleteLast());
        assert(q.getRear() == 0);
    }
    return 0;
}
