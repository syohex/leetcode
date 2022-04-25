#include <cassert>
#include <vector>

class Iterator {
  public:
    explicit Iterator(const std::vector<int> &nums) : nums_(nums), it_(nums_.begin()) {
    }

    int next() {
        int ret = *it_;
        ++it_;
        return ret;
    }

    bool hasNext() const {
        return it_ != nums_.end();
    }

    std::vector<int> nums_;
    std::vector<int>::iterator it_;
};

class PeekingIterator : public Iterator {
  public:
    PeekingIterator(const std::vector<int> &nums) : Iterator(nums), peeked_(false), value_(-1) {
    }

    int peek() {
        if (!peeked_) {
            peeked_ = true;
            value_ = Iterator::next();
        }

        return value_;
    }

    int next() {
        if (peeked_) {
            peeked_ = false;
            return value_;
        }

        return Iterator::next();
    }

    bool hasNext() const {
        if (peeked_) {
            return true;
        }

        return Iterator::hasNext();
    }

    bool peeked_;
    int value_;
};

int main() {
    {
        std::vector<int> nums{1, 2, 3};
        PeekingIterator p(nums);
        assert(p.next() == 1);
        assert(p.hasNext());
        assert(p.peek() == 2);
        assert(p.next() == 2);
        assert(p.next() == 3);
        assert(!p.hasNext());
    }
    return 0;
}