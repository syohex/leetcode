#include <cassert>
#include <vector>

class Iterator {
  public:
    struct Data;
    Data *data;

    Iterator(const std::vector<int> &nums) : nums_(nums), pos_(0) {
    }
    // Iterator(const Iterator& iter);

    int next() {
        return nums_[pos_++];
    }

    bool hasNext() const {
        return pos_ < nums_.size();
    }

    std::vector<int> nums_;
    size_t pos_;
};

class PeekingIterator : public Iterator {
  public:
    PeekingIterator(const std::vector<int> &nums) : Iterator(nums) {
        peeked_ = false;
        peeked_value_ = 0;
    }

    int peek() {
        if (!peeked_) {
            peeked_value_ = Iterator::next();
            peeked_ = true;
        }

        return peeked_value_;
    }

    int next() {
        if (peeked_) {
            peeked_ = false;
            return peeked_value_;
        }

        return Iterator::next();
    }

    bool hasNext() const {
        return peeked_ || Iterator::hasNext();
    }

    bool peeked_;
    int peeked_value_;
};

int main() {
    {
        std::vector<int> input{1, 2, 3};
        PeekingIterator p(input);
        assert(p.peek() == 1);
        assert(p.next() == 1);
        assert(p.hasNext());
        assert(p.peek() == 2);
        assert(p.next() == 2);
        assert(p.peek() == 3);
        assert(p.hasNext());
        assert(p.next() == 3);
        assert(!p.hasNext());
    }
    return 0;
}
