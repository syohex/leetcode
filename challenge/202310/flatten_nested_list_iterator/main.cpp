#include <cassert>
#include <vector>
#include <cstdio>

class NestedInteger {
  public:
    explicit NestedInteger(int n) : n_(n), is_integer_(true) {
    }

    explicit NestedInteger(const std::vector<NestedInteger> &v) : v_(v), is_integer_(false) {
    }

    bool isInteger() const {
        return is_integer_;
    }

    int getInteger() const {
        return n_;
    }

    const std::vector<NestedInteger> &getList() const {
        return v_;
    }

    int n_;
    std::vector<NestedInteger> v_;
    bool is_integer_;
};

class NestedIterator {
  public:
    NestedIterator(const std::vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }

    void flatten(const std::vector<NestedInteger> &nestedList) {
        for (const auto &ni : nestedList) {
            if (ni.isInteger()) {
                v_.push_back(ni.getInteger());
            } else {
                const auto &list = ni.getList();
                flatten(list);
            }
        }
    }

    int next() {
        return v_[index_++];
    }

    bool hasNext() {
        return index_ < v_.size();
    }

    std::vector<int> v_;
    size_t index_ = 0;
};

int main() {
    {
        std::vector<NestedInteger> nl;
        nl.push_back(NestedInteger({NestedInteger(1), NestedInteger(1)}));
        nl.push_back(NestedInteger(2));
        nl.push_back(NestedInteger({NestedInteger(1), NestedInteger(1)}));

        std::vector<int> expected{1, 1, 2, 1, 1};

        std::vector<int> ret;
        NestedIterator it(nl);
        while (it.hasNext()) {
            ret.push_back(it.next());
        }

        assert(ret == expected);
    }
    {
        std::vector<NestedInteger> nl;
        nl.push_back(NestedInteger({NestedInteger(1), NestedInteger({NestedInteger(4), NestedInteger({NestedInteger(6)})})}));
        std::vector<int> expected{1, 4, 6};

        std::vector<int> ret;
        NestedIterator it(nl);
        while (it.hasNext()) {
            ret.push_back(it.next());
        }

        assert(ret == expected);
    }
    return 0;
}
