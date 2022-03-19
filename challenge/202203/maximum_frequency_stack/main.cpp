#include <cassert>
#include <queue>
#include <map>
#include <vector>
#include <cstdio>

class FreqStack {
  public:
    struct Data {
        int value;
        int id;
        int count;

        bool operator<(const Data &d) const {
            if (count != d.count) {
                return count < d.count;
            }

            return id < d.id;
        }
    };

    FreqStack() : id_(0) {
    }

    void push(int x) {
        ++count_[x];
        q_.push({x, id_++, count_[x]});
    }

    int pop() {
        int ret = q_.top().value;
        q_.pop();

        --count_[ret];
        return ret;
    }

    std::priority_queue<Data, std::vector<Data>> q_;
    std::map<int, int> count_;
    int id_;
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
