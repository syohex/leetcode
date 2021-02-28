#include <cassert>
#include <vector>
#include <map>
#include <queue>

class FreqStack {
  public:
    FreqStack() : id_(0) {
    }

    struct Data {
        int count;
        int id;
        int num;

        bool operator<(const Data &other) const {
            if (count != other.count) {
                return count < other.count;
            }

            return id < other.id;
        }
    };

    void push(int x) {
        ++count_[x];
        queue_.push(Data{count_[x], id_++, x});
    }

    int pop() {
        int ret = queue_.top().num;
        queue_.pop();
        --count_[ret];
        return ret;
    }

    std::map<int, int> count_;
    std::priority_queue<Data, std::vector<Data>> queue_;
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
