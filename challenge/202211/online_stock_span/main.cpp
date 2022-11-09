#include <cassert>
#include <queue>
#include <vector>
#include <cstdio>

struct Data {
    size_t pos;
    int val;
};

struct Compare {
    bool operator()(const Data &a, const Data &b) const {
        if (a.val == b.val) {
            return a.pos > b.pos;
        }

        return a.val < b.val;
    }
};

class StockSpanner {
  public:
    StockSpanner() : pos_(0) {
        q_.push({0, 0});
    }

    int next(int price) {
        size_t len = q_.size();
        std::vector<Data> tmp;

        Data bigger_point{0, 0};
        while (!q_.empty()) {
            Data d = q_.top();
            if (d.val <= price) {
                break;
            }

            if (d.pos > bigger_point.pos) {
                bigger_point = d;
            }

            q_.pop();
            tmp.push_back(d);
        }

        int ret = len - bigger_point.pos;

        for (Data &d : tmp) {
            q_.emplace(std::move(d));
        }

        q_.push({len, price});
        return ret;
    }

    std::priority_queue<Data, std::vector<Data>, Compare> q_;
    size_t pos_;
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
