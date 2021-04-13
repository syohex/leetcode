#include <cassert>
#include <vector>
#include <stack>

class NestedInteger {
  public:
    NestedInteger(int value) : value_(value), is_integer_(true) {
    }
    NestedInteger(const std::vector<NestedInteger> &list) : list_(list), is_integer_(false) {
    }
    bool isInteger() const {
        return is_integer_;
    }
    int getInteger() const {
        return value_;
    }
    const std::vector<NestedInteger> &getList() const {
        return list_;
    }

    int value_;
    std::vector<NestedInteger> list_;
    bool is_integer_;
};

class NestedIterator {
  public:
    NestedIterator(std::vector<NestedInteger> &nestedList) : pos_(0) {
        flatten(nestedList);
    }

    void flatten(const std::vector<NestedInteger> &list) {
        for (const auto &n : list) {
            if (n.isInteger()) {
                v_.push_back(n.getInteger());
            } else {
                flatten(n.getList());
            }
        }
    }

    int next() {
        return v_[pos_++];
    }

    bool hasNext() {
        return pos_ < v_.size();
    }

    std::vector<int> v_;
    size_t pos_;
};

int main() {
    {
        std::vector<NestedInteger> v{
            NestedInteger(std::vector<NestedInteger>{NestedInteger(1), NestedInteger(1)}),
            NestedInteger(2),
            NestedInteger(std::vector<NestedInteger>{NestedInteger(1), NestedInteger(1)}),
        };

        NestedIterator iter(v);
        std::vector<int> expected{1, 1, 2, 1, 1};
        for (int n : expected) {
            assert(iter.next() == n);
        }

        assert(!iter.hasNext());
    }
    {
        std::vector<NestedInteger> v{
            NestedInteger(1),
            NestedInteger(std::vector<NestedInteger>{NestedInteger(4), NestedInteger(std::vector<NestedInteger>{6})}),
        };

        NestedIterator iter(v);
        std::vector<int> expected{1, 4, 6};
        for (int n : expected) {
            assert(iter.next() == n);
        }

        assert(!iter.hasNext());
    }
    return 0;
}
