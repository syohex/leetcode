#include <cassert>
#include <queue>
#include <vector>
#include <cstdio>

class FreqStack {
  public:
    struct Data {
        int value;
        std::vector<int> positions;
    };

    struct Compare {
        bool operator()(Data &a, Data &b) const {
            if (a.positions.size() == b.positions.size()) {
                return a.positions.back() < b.positions.back();
            }

            return a.positions.size() < b.positions.size();
        }
    };

    FreqStack() : pos_(0) {
    }

    void push(int x) {
        std::vector<Data> tmp;
        bool found = false;
        while (!q_.empty()) {
            Data d = q_.top();
            q_.pop();

            if (d.value == x) {
                d.positions.push_back(pos_);
                q_.push(d);
                found = true;
                break;
            }

            tmp.push_back(std::move(d));
        }

        if (!found) {
            q_.push({x, {pos_}});
        }

        for (auto &&a : tmp) {
            q_.push(a);
        }

        ++pos_;
    }

    int pop() {
        Data d = q_.top();
        q_.pop();

        int ret = d.value;
        d.positions.pop_back();

        if (!d.positions.empty()) {
            q_.push(std::move(d));
        }

        return ret;
    }

    std::priority_queue<Data, std::vector<Data>, Compare> q_;
    int pos_;
};

int main() {
    {
        FreqStack f;
        f.push(5);
        f.push(7);
        f.push(5);
        f.push(7);
        f.push(4);
        f.push(5);
        assert(f.pop() == 5);
        assert(f.pop() == 7);
        assert(f.pop() == 5);
        assert(f.pop() == 4);
    }
    return 0;
}
