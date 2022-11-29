#include <cassert>
#include <vector>
#include <unordered_set>
#include <random>
#include <algorithm>

class RandomizedSet {
  public:
    RandomizedSet() : mt_(rnd_()) {
    }

    bool insert(int val) {
        if (s_.find(val) != s_.end()) {
            return false;
        }

        s_.insert(val);
        v_.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (s_.find(val) == s_.end()) {
            return false;
        }

        auto it = std::find(v_.begin(), v_.end(), val);
        size_t index = std::distance(v_.begin(), it);
        v_[index] = v_.back();
        v_.pop_back();

        s_.erase(val);
        return true;
    }

    int getRandom() {
        std::uniform_int_distribution<> rand(0, static_cast<int>(v_.size() - 1));
        return v_[rand(mt_)];
    }

    std::unordered_set<int> s_;
    std::vector<int> v_;
    std::random_device rnd_;
    std::mt19937 mt_;
};

int main() {
    {
        RandomizedSet r;
        assert(r.insert(1));
        assert(!r.remove(2));
        assert(r.insert(2));

        int v = r.getRandom();
        assert(v == 1 || v == 2);
        assert(r.remove(1));
        assert(!r.insert(2));
        assert(r.getRandom() == 2);
    }
    {
        RandomizedSet r;
        assert(r.insert(0));
        assert(r.insert(1));
        assert(r.remove(0));
        assert(r.insert(2));
        assert(r.remove(1));
        assert(r.getRandom() == 2);
    }
    return 0;
}
