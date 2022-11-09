#include <cassert>
#include <stack>
#include <vector>
#include <cstdio>

class StockSpanner {
  public:
    StockSpanner() {
    }

    int next(int price) {
        int ret = 1;

        while (!stack_.empty()) {
            auto p = stack_.top();
            if (p.first > price) {
                break;
            }

            ret += p.second;
            stack_.pop();
        }

        stack_.push({price, ret});
        return ret;
    }

    std::stack<std::pair<int, int>> stack_;
};

int main() {
    {
        StockSpanner s;
        assert(s.next(100) == 1);
        assert(s.next(80) == 1);
        assert(s.next(60) == 1);
        assert(s.next(70) == 2);
        assert(s.next(60) == 1);
        assert(s.next(75) == 4);
        assert(s.next(85) == 6);
    }
    {
        StockSpanner s;
        assert(s.next(100) == 1);
        assert(s.next(80) == 1);
        assert(s.next(60) == 1);
        assert(s.next(90) == 3);
        assert(s.next(60) == 1);
        assert(s.next(75) == 2);
        assert(s.next(85) == 3);
    }
    return 0;
}
