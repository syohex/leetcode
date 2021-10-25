#include <cassert>
#include <stack>
#include <map>
#include <algorithm>
#include <climits>

class MinStack {
  public:
    MinStack() : min_(INT_MAX) {
    }

    void push(int val) {
        min_ = std::min(min_, val);
        stack_.push(val);
        ++map_[val];
    }

    void pop() {
        int val = stack_.top();
        stack_.pop();

        --map_[val];
        if (map_[val] == 0) {
            map_.erase(val);

            if (val == min_) {
                min_ = INT_MAX;
                for (const auto &it : map_) {
                    min_ = std::min(min_, it.first);
                }
            }
        }
    }

    int top() {
        return stack_.top();
    }

    int getMin() {
        return min_;
    }

    std::stack<int> stack_;
    int min_;
    std::map<int, int> map_;
};

int main() {
    {
        MinStack m;
        m.push(-2);
        m.push(0);
        m.push(-3);
        assert(m.getMin() == -3);
        m.pop();
        assert(m.top() == 0);
        assert(m.getMin() == -2);
    }

    return 0;
}
