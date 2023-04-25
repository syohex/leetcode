#include <cassert>
#include <vector>
#include <set>

class SmallestInfiniteSet {
  public:
    SmallestInfiniteSet() {
    }

    int popSmallest() {
        for (int i = 1;; ++i) {
            if (not_exists_.find(i) == not_exists_.end()) {
                not_exists_.insert(i);
                return i;
            }
        }

        // never reach here
        return -1;
    }

    void addBack(int num) {
        if (not_exists_.find(num) == not_exists_.end()) {
            return;
        }

        not_exists_.erase(num);
    }

    std::set<int> not_exists_;
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
