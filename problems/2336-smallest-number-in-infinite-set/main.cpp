#include <cassert>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>

class SmallestInfiniteSet {
  public:
    SmallestInfiniteSet() : num_(1) {
    }

    int popSmallest() {
        if (!q_.empty()) {
            int num = q_.top();
            q_.pop();

            backs_.erase(num);
            return num;
        }

        return num_++;
    }

    void addBack(int num) {
        if (num >= num_) {
            return;
        }

        if (backs_.find(num) == backs_.end()) {
            q_.push(num);
            backs_.insert(num);
        }
    }

    int num_;
    std::set<int> backs_;
    std::priority_queue<int, std::vector<int>, std::greater<int>> q_;
};

int main() {
    {
        SmallestInfiniteSet s;
        s.addBack(2);
        assert(s.popSmallest() == 1);
        assert(s.popSmallest() == 2);
        assert(s.popSmallest() == 3);
        s.addBack(1);
        assert(s.popSmallest() == 1);
        assert(s.popSmallest() == 4);
        assert(s.popSmallest() == 5);
    }
    {
        SmallestInfiniteSet s;
        assert(s.popSmallest() == 1);
        assert(s.popSmallest() == 2);
        s.addBack(3);
        assert(s.popSmallest() == 3);
        s.addBack(2);
        assert(s.popSmallest() == 2);
        assert(s.popSmallest() == 4);
    }
    return 0;
}
