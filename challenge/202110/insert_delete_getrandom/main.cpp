#include <cassert>
#include <random>
#include <set>

class RandomizedSet {
  public:
    RandomizedSet() : mt_(rnd_()) {
    }

    bool insert(int val) {
        if (set_.find(val) != set_.end()) {
            return false;
        }

        set_.insert(val);
        return true;
    }

    bool remove(int val) {
        if (set_.find(val) == set_.end()) {
            return false;
        }

        set_.erase(val);
        return true;
    }

    int getRandom() {
        std::uniform_int_distribution<int> dist(0, static_cast<int>(set_.size() - 1));
        int index = dist(mt_);
        int i = 0;
        for (auto it = set_.begin(); it != set_.end(); ++it, ++i) {
            if (i == index) {
                return *it;
            }
        }

        // never reach here
        return -1;
    }

    std::random_device rnd_;
    std::mt19937 mt_;
    std::set<int> set_;
};

int main() {
    {
        RandomizedSet r;
        assert(r.insert(1));
        assert(!r.remove(2));
        assert(r.insert(2));
        auto ret = r.getRandom();
        assert(ret == 1 || ret == 2);
        assert(r.remove(1));
        assert(!r.insert(2));
        ret = r.getRandom();
        assert(ret == 2);
    }
    return 0;
}