#include <cassert>
#include <vector>
#include <map>
#include <queue>
#include <list>

class FreqStack {
  public:
    FreqStack() {
    }

    void push(int x) {
        ++count_[x];
        queue_.push_front(x);
    }

    int pop() {
        int max = 0;
        for (const auto &it : count_) {
            if (it.second > max) {
                max = it.second;
            }
        }

        std::vector<int> candidates;
        for (const auto &it : count_) {
            if (it.second == max) {
                candidates.push_back(it.first);
            }
        }

        for (auto it = queue_.begin(); it != queue_.end(); ++it) {
            for (auto n : candidates) {
                if (*it == n) {
                    queue_.erase(it);
                    --count_[n];
                    return n;
                }
            }
        }

        return -1;
    }

    std::map<int, int> count_;
    std::deque<int> queue_;
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
