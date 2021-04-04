#include <cassert>
#include <vector>

class MyCircularQueue {
  public:
    MyCircularQueue(int k) : size_(k), front_(0), rear_(k - 1), queue_(size_), count_(0) {
    }

    bool enQueue(int value) {
        if (count_ >= size_) {
            return false;
        }

        rear_ = (rear_ + 1) % size_;
        queue_[rear_] = value;
        ++count_;
        return true;
    }

    bool deQueue() {
        if (count_ == 0) {
            return false;
        }

        front_ = (front_ + 1) % size_;
        --count_;
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
        return queue_[rear_];
    }

    bool isEmpty() {
        return count_ == 0;
    }

    bool isFull() {
        return count_ == size_;
    }

    int size_;
    int front_;
    int rear_;
    std::vector<int> queue_;
    int count_;
};

int main() {
    {
        auto q = MyCircularQueue(3);
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
        auto q = MyCircularQueue(6);
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
        auto q = MyCircularQueue(3);
        assert(q.enQueue(2));
        assert(q.Rear() == 2);
        assert(q.Front() == 2);
    }
    return 0;
}