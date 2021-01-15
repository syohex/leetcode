#include <cassert>
#include <vector>
#include <functional>

class NestedInteger {
  public:
    NestedInteger() : value_(0), is_integer_(false) {
    }

    NestedInteger(int value) : value_(value), is_integer_(true) {
    }

    bool isInteger() const {
        return is_integer_;
    }

    int getInteger() const {
        return value_;
    }

    void setInteger(int value) {
        value_ = value;
    }

    void add(const NestedInteger &ni) {
        v_.push_back(ni);
    }

    const std::vector<NestedInteger> &getList() const {
        return v_;
    }

  private:
    int value_;
    bool is_integer_;
    std::vector<NestedInteger> v_;
};

int depthSum(const std::vector<NestedInteger> &nestedList) {
    std::function<int(const std::vector<NestedInteger> &es, int depth)> f;
    f = [&f](const std::vector<NestedInteger> &es, int depth) -> int {
        int sum = 0;
        for (const auto &e : es) {
            if (e.isInteger()) {
                sum += e.getInteger() * depth;
            } else {
                sum += f(e.getList(), depth + 1);
            }
        }

        return sum;
    };

    return f(nestedList, 1);
}

int main() {
    {
        // [1, 2, 3]
        std::vector<NestedInteger> input;
        input.push_back(NestedInteger(1));
        input.push_back(NestedInteger(2));
        input.push_back(NestedInteger(3));
        assert(depthSum(input) == 6);
    }
    {
        // [[1, 1], 2, [1, 1]]
        std::vector<NestedInteger> input;
        NestedInteger e1;
        e1.add(NestedInteger(1));
        e1.add(NestedInteger(1));

        NestedInteger e2(2);

        input.push_back(e1);
        input.push_back(e2);
        input.push_back(e1);

        assert(depthSum(input) == 10);
    }
    {
        // [1, [4, [6]]]
        std::vector<NestedInteger> input;
        input.push_back(NestedInteger(1));

        NestedInteger e2;
        e2.add(NestedInteger(4));

        NestedInteger e3;
        e3.add(NestedInteger(6));
        e2.add(e3);

        input.push_back(e2);

        assert(depthSum(input) == 27);
    }
    return 0;
}
