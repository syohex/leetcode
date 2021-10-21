#include <cassert>
#include <map>
#include <vector>
#include <random>
#include <algorithm>

class RandomizedSet {
  public:
    RandomizedSet() : array_(1'000'000), pos_(0), mt_(rnd_()) {
    }

    bool insert(int val) {
        if (map_.find(val) != map_.end()) {
            return false;
        }

        map_[val] = pos_;
        array_[pos_] = val;
        ++pos_;
        return true;
    }

    bool remove(int val) {
        if (map_.find(val) == map_.end()) {
            return false;
        }

        int last_val = array_[pos_ - 1];
        size_t index = map_[val];

        array_[index] = last_val;
        map_[last_val] = index;

        --pos_;
        map_.erase(val);
        return true;
    }

    int getRandom() {
        std::uniform_int_distribution<int> dist(0, static_cast<int>(map_.size() - 1));
        int index = dist(mt_);
        return array_[index];
    }

    std::map<int, size_t> map_;
    std::vector<int> array_;
    size_t pos_;
    std::random_device rnd_;
    std::mt19937 mt_;
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
    {
        RandomizedSet r;
        assert(r.insert(0));
        assert(r.insert(1));
        assert(r.remove(0));
        assert(r.insert(2));
        assert(r.remove(1));
        auto ret = r.getRandom();
        assert(ret == 2);
    }
    return 0;
}