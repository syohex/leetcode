#include <cassert>
#include <vector>

class MyCircularQueue {
  public:
    MyCircularQueue(int k) : size_(k), count_(0), front_(0), end_(0), queue_(k) {
    }

    bool enQueue(int value) {
        if (count_ >= size_) {
            return false;
        }

        ++count_;
        queue_[end_] = value;
        end_ = (end_ + 1) % size_;
        return true;
    }

    bool deQueue() {
        if (count_ == 0) {
            return false;
        }

        --count_;
        front_ = (front_ + 1) % size_;
        return true;
    }

    int Front() {
        if (count_ == 0) {
            return -1;
        }

        return queue_[front_];
    }

    int Rear() {
        if (count_ == 0) {
            return -1;
        }

        int last = (end_ + size_ - 1) % size_;
        return queue_[last];
    }

    bool isEmpty() {
        return count_ == 0;
    }

    bool isFull() {
        return count_ == size_;
    }

  private:
    int size_;
    int count_;
    int front_;
    int end_;
    std::vector<int> queue_;
};

int main() {
    {
        MyCircularQueue q(3);
        assert(q.enQueue(1));
        assert(q.enQueue(2));
        assert(q.enQueue(3));
        assert(!q.enQueue(4));
        assert(q.Rear() == 3);
        assert(q.isFull());
        assert(q.deQueue());
        assert(q.enQueue(4));
        assert(q.Rear() == 4);
    }
    {
        MyCircularQueue q(6);
        assert(q.enQueue(6));
        assert(q.Rear() == 6);
        assert(q.Rear() == 6);
        assert(q.deQueue());
        assert(q.enQueue(5));
        assert(q.Rear() == 5);
        assert(q.deQueue());
        assert(q.Front() == -1);
        assert(!q.deQueue());
        assert(!q.deQueue());
        assert(!q.deQueue());
    }
    {
        MyCircularQueue q(3);
        assert(q.enQueue(2));
        assert(q.Rear() == 2);
        assert(q.Front() == 2);
        assert(q.deQueue());
        assert(q.Front() == -1);
        assert(!q.deQueue());
        assert(q.Front() == -1);
        assert(q.enQueue(4));
        assert(q.enQueue(2));
        assert(q.enQueue(2));
        assert(!q.enQueue(3));
    }
    return 0;
}